#include <iostream>
using namespace std;

int beautySum(string s) 
{
    int beauty = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) 
    {
        int frq[26] = {0}; // array of the 26 letters of the alphabet using ASCII
        for (int j = i; j < n; j++) 
        {
            frq[s[j] - 'a']++;
            // Find max and min frq in the substring
            int maxFrq = 0, minFrq = n;
            for (int k = 0; k < 26; k++)
            {
                if (frq[k] > 0) 
                {
                    maxFrq = max(maxFrq, frq[k]);
                    minFrq = min(minFrq, frq[k]);
                }
            }
            beauty += (maxFrq - minFrq); // Sum the beauty of each substring
        }
    }

    return beauty;
}

int main() 
{
    string s1 = "aabcb";
    cout << "- Total beauty of substrings in '" << s1 << "' is : " << beautySum(s1) << endl;

    string s2 = "aabcbaa";
    cout << "- Total beauty of substrings in '" << s2 << "' is : " << beautySum(s2) << endl;

    return 0;
}
