#include <iostream>
using namespace std;

string sortStringByFrq(string s) 
{
    int frq[256] = {0};
    // Store the frequency of each character using ASCII values
    for (int i = 0; i < s.length(); i++) 
    {
        frq[s[i]]++;
    }
    // Sort the string by frequency
    string res = "";
    while (true) 
    {
        int maxFrq = 0;
        char maxChar = 0;
        // Find the character with the highest frequency
        for (int i = 0; i < 256; i++) 
        {
            if (frq[i] > maxFrq) 
            {
                maxFrq = frq[i];
                maxChar = i;
            }
        }
        if (maxFrq == 0) // if the frq array is empty which means maxFrq is 0 
        {
            break;
        }
        // Append the character maxFreq times
        for (int i = 0; i < maxFrq; i++) 
        {
            res += maxChar;
        }
        frq[maxChar] = 0;
    }
    return res;
}

int main() 
{
    string s1 = "tree";
    cout << "- Sorted characters in " << s1 << " : " << sortStringByFrq(s1) << endl;
    
    string s2 = "cccaaa";
    cout << "- Sorted characters in " << s2 << " : " << sortStringByFrq(s2) << endl;
    
    string s3 = "Aabb";
    cout << "- Sorted characters in " << s3 << " : " << sortStringByFrq(s3) << endl;
    
    return 0;
}
