#include <iostream>
using namespace std;

void reverseWord(string &s, int start, int end) // Function to reverse one word
{
    while (start < end) 
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

string reverseEachWord(string s) 
{
    int n = s.length();
    int i = 0;
    while (i < n) // Get the starting and ending index
    {
        while (i < n && s[i] == ' ') i++;
        int start = i;
        while (i < n && s[i] != ' ') i++;
        reverseWord(s, start, i - 1); // Pass the string, start and end into reverseWord function
    }

    return s;
}

int main() 
{
    string s1 = "the sky is blue";
    cout << "- '" << s1 << "' with each word reversed : " << reverseEachWord(s1) << endl;

    string s2 = "  hello world  ";
    cout << "- '" << s2 << "' with each word reversed : " << reverseEachWord(s2) << endl;

    string s3 = "a good   example";
    cout << "- '" << s2 << "' with each word reversed : " << reverseEachWord(s3) << endl;

    return 0;
}
