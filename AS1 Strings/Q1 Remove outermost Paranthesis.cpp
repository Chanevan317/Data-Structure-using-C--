#include <iostream>
using namespace std;

string removeOuterParenthesis(string s) 
{
    int count = 0;
    string ans = "";
    int i = 0, n = s.size();
    while(i < n) 
    {
        if(s[i] == '(') 
        {
            if(count != 0) 
            {
                ans += s[i];
            }
            count++; 
        } 
        else if (s[i] == ')') 
        {
            if(count > 1) 
            {
                ans += s[i];
            }
            count--; 
        }
        i++;
    }
    return ans;
}

int main()
{
    string s = "(()())(())(()(()))";
    cout << "Before removing the outer parenthesis : " << s << endl;
    cout << "After removing the outer parenthesis : " << removeOuterParenthesis(s);
    return 0;
}