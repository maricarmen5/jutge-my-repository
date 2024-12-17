#include "sameExtension.hpp"

string get_extension(string s, string ext)
{   
    unsigned int i = 0;
    bool found = false;

    while ((not found) and i < s.size()) {
        if (s[i] == '.') {
            ext = s.substr(i);
            found = true;
        }

        ++i;
    }

    return ext;
}

bool sameExtension_aux(const BinaryTree<string>& t, string& ext) 
{
    bool ans = true;

    // Fita: t.height
    if (not t.isEmpty()) {
        if (t.getRight().isEmpty() and t.getLeft().isEmpty()) {
            string ext_aux = get_extension(t.getRoot(), ext);

            if (ext == " ") ext = ext_aux;
            else if (ext_aux != ext) ans = false;
        }
        else {
            bool left = sameExtension_aux(t.getLeft(), ext);

            if (not left) ans = false;
            else ans = sameExtension_aux(t.getRight(), ext);
            // HI: left child files have the same extension
        }
    }

    return ans;
}

bool sameExtension(const BinaryTree<string> &t)
{
    string ext = " "; // ext is the current extension
    bool ans = sameExtension_aux(t, ext); 
    return ans;
}