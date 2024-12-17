#include <iostream>
#include <vector>
using namespace std;

// solució de l'Element més freqüent sense utilitzar map

int dichotomic_search(const vector<int>& seq, int elem)
{
    int ans = -1;
    int min = 0;
    int max = seq.size() - 1;
    
    while (min <= max) {
        int mid = min + (max - min)/2;

        if (seq[mid] == elem) {
            ans = mid;
            min = mid + 1;
        }
        else if (seq[mid] < elem) min = mid + 1;
        else max = mid - 1;
    }

    return ans;
}

int frequency_in_seq(const vector<int>& seq, const vector<int>& freq, int elem)
{
    int ans = 0;

    int index = dichotomic_search(seq, elem);
    if (index != -1) ans = freq[index];

    return ans;
}

int main ()
{
    int size;
    while (cin >> size) {
        vector<int> seq;
        vector<int> freq;

        
        int prev_elem = -1;
        int max_freq = 0;
        int max_elem = 0;
        int elem;
        for (int i = 0; i < size; ++i) {
            cin >> elem;
    
            if (prev_elem < elem) {
                seq.push_back(elem);
                freq.push_back(1);
            } 
            else ++freq[freq.size() - 1];

            if (max_freq <= freq[freq.size() - 1]) {
                max_freq = freq[freq.size() - 1];
                max_elem = seq[seq.size() - 1];
            }

            prev_elem = elem;
        }
        
        prev_elem = -1;
        int current_freq = 0;
        cin >> size;
        for (int i = 0; i < size; ++i) {
            cin >> elem;

            if (prev_elem < elem) {
                current_freq = 1 + frequency_in_seq(seq, freq, elem);
            } 
            else ++current_freq;

            if ((max_freq == current_freq and max_elem < elem) 
            or (max_freq < current_freq)) {
                max_freq = current_freq;
                max_elem = elem;
            }

            prev_elem = elem;
        }

        cout << max_elem << ' ' << max_freq << endl;
    }
}
