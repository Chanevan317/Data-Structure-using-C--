#include <iostream>
using namespace std;

int numberOfSubstring(string s, int k)
{
    int n = s.length();
    int count = 0;

    for (int i = 0; i < n; i++) 
    {
        int frq[26] = {0}; // array of the 26 letters of the alphabet using ASCII
        int distinctCnt = 0; // Keep the count of how many distinct letters are there
        for (int j = i; j < n; j++) 
        {
            // Get index of the character
            int index = s[j] - 'a';
            // If this character is seen for the first time
            if (frq[index] == 0) 
            {
                distinctCnt++;
            }
            // Increment frequency of the character
            frq[index]++;
            // If we have exactly k distinct characters
            if (distinctCnt == k) 
            {
                count++;
            }
            // If we have more than k distinct characters
            else if (distinctCnt > k) 
            {
                break;
            }
        }
    }

    return count;
}

int main()
{
    string s1 = "aba";
    int k = 2;
    cout << "- Number of substring in '" << s1 << "' having exactly " << k << " distinct characters : " << numberOfSubstring(s1, k) << endl;

    string s2 = "abaaca";
    k = 1;
    cout << "- Number of substring in '" << s2 << "' having exactly " << k << " distinct characters : " << numberOfSubstring(s2, k) << endl;

    return 0;
}