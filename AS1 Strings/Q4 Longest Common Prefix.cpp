#include <iostream>
using namespace std;

string longestCommonPrefix(int size, string strs[]) 
{
    if (size == 0) return "";
    string prefix = strs[0];
    for (int i = 1; i < size; i++) 
    {
        int j = 0;
        while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) 
        {
            j++; // get the last index of the prefix
        }
        prefix = prefix.substr(0, j);  // Get the prefix
    }
    return prefix;
}

int main() {
    string strs1[3] = {"flower" ,"flow" ,"flight"};
    cout << "Common prefix in strs1 : " << longestCommonPrefix(3, strs1) << endl;
    string strs2[3] = {"dog" ,"racecar" ,"car"};
    cout << "Common prefix in strs2 : " << longestCommonPrefix(3, strs2) << endl;
    return 0;
}
