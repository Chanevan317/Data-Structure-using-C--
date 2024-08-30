#include <iostream>
using namespace std;

bool isIsomorphic(string s, string t) 
{
    int mapS[128] = {0}; // To map characters from s to t
    int mapT[128] = {0}; // To map characters from t to s
    int len = s.length();
    if (len != t.length()) return false;
    for (int i = 0; i < len; ++i) 
    {
        if (mapS[s[i]] != mapT[t[i]]) 
        {
            return false;
        }
        mapS[s[i]] = i + 1;
        mapT[t[i]] = i + 1;
    }

    return true;
}

int main() 
{
    string s1 = "egg", t1 = "add";
    cout << "Are '" << s1 << "' and '" << t1 << "' isomorphic ? ";
    cout << "=> " << (isIsomorphic(s1, t1) ? "true" : "false") << endl;

    string s2 = "foo", t2 = "bar";
    cout << "Are '" << s2 << "' and '" << t2 << "' isomorphic ? ";
    cout << "=> " << (isIsomorphic(s2, t2) ? "true" : "false") << endl;

    string s3 = "paper", t3 = "title";
    cout << "Are '" << s3 << "' and '" << t3 << "' isomorphic ? ";
    cout << "=> " << (isIsomorphic(s3, t3) ? "true" : "false") << endl;

    return 0;
}
