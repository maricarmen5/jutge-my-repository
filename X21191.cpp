#include <iostream>
#include <vector>
using namespace std;

int mitjana_menor(const vector<int> &v, int k)
{	
	int pos = v.size() - 1;
	int sum = 0;
	double average = 100000;
	
	int ans = pos;
	
	for (int i = pos; -1 < i; --i) {
		// Inv: ans conté l'índex del primer element del subvector amb 
		// la mitjana menor dels subvectors possibles de mida k 
		// començant per la dreta fins v[i]
		sum += v[i];
		if (i < (int)v.size() - k) sum -= v[i + k];
		
		if (i <= (int)v.size() - k) {
			if ((double)sum/k <= average) {
				average = (double)sum/k;
				ans = i;
			}
		}
	}
	
	return ans;
}

int main ()
{
	int size;
	cin >> size;
	
	vector<int> v(size);
	for (int i = 0; i < size; ++i) cin >> v[i];
	
	cout << '[';
	for (int i = 0; i < size; ++i) {
		if (i != 0) cout << ',';
		cout << v[i];
	}
	cout << ']' << endl;
	
	int k;
	while (cin >> k) cout << mitjana_menor(v, k) << endl;
}
	
