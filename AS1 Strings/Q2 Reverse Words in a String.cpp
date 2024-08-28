#include <iostream>
using namespace std;

string reverseWords(string s) 
{
    string ans = "";
    int k = s.size();
    for(int i = s.size(); i >=0; i--)
    {
        if(s[i] == ' ') 
        {
            for(int j = i+1; j < k; j++)
            {
                ans += s[j];
            }
            ans += ' ';
            k = i;
        }
        if(i == 0)
        {
            for(int j = i; j < k; j++)
            {
                ans += s[j];
            }
        } 
    }
    return ans;
}

int main()
{
    string s = "this is an amazing program";
    cout << "Before reversing the words : " << s << endl;
    cout << "After reversing the words : " << reverseWords(s);
    return 0;
}