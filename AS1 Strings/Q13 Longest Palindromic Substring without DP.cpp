#include <iostream>
using namespace std;

string longestPalindrome(string s) 
{
    int start = 0, maxLength = 1;
    int n = s.length();

    for (int i = 0; i < n; i++) 
    {
        // Check for odd-length palindrome
        int low = i, high = i;
        while (low >= 0 && high < n && s[low] == s[high]) 
        {
            int length = high - low + 1;
            if (length > maxLength) {
                start = low;
                maxLength = length;
            }
            low--;
            high++;
        }
        // Check for even-length palindrome
        low = i, high = i + 1;
        while (low >= 0 && high < n && s[low] == s[high]) 
        {
            int length = high - low + 1;
            if (length > maxLength) {
                start = low;
                maxLength = length;
            }
            low--;
            high++;
        }
    }

    return s.substr(start, maxLength);
}

int main() 
{
    string s1 = "babad";
    cout << "- Longest Palindromic Substring of '" << s1 << "' is : " << longestPalindrome(s1) << endl;

    string s2 = "cbbd";
    cout << "- Longest Palindromic Substring of '" << s2 << "' is : " << longestPalindrome(s2) << endl;

    return 0;
}
