#include <iostream>
using namespace std;

string isAnagram(string s, string ana) 
{
    int n = s.length();
    if (n != ana.length()) return "false";
    // ASCII code from 65 to 122 ('A' to 'z')
    int countS[63] = {0};
    int countAna[63] = {0};
    for (int i = 0; i < n; i++) 
    {
        countS[s[i] - 'A']++; 
        countAna[ana[i] - 'A']++;
    }
    for (int i = 0; i < 63; i++) 
    {
        if (countS[i] != countAna[i]) 
        {
            return "false";
        }
    }
    return "true";
}

int main() {
    string s1 = "CAT", ana1 = "ACT";
    cout << "Are '" << s1 << "' and '" << ana1 << "' anagram of each other ?\n" << "=> " << isAnagram(s1, ana1) << endl;
    string s2 = "RULES", ana2 = "LESRT";
    cout << "Is '" << s2 << "' and '" << ana2 << "' anagram of each other ?\n" << "=> " << isAnagram(s2, ana2) << endl;
    return 0;
}
