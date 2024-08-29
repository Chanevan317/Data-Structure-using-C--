#include <iostream>
using namespace std;

int nestingDepth(string s) 
{
    int currentDepth = 0;
    int maxDepth = 0;
    for (char ch : s) 
    {
        if (ch == '(') 
        {
            currentDepth++;
            if (currentDepth > maxDepth) 
            {
                maxDepth = currentDepth;
            }
        } 
        else if (ch == ')') 
        {
            currentDepth--;
        }
    }
    return maxDepth;
}

int main() 
{
    string s1 = "(1+(2*3)+((8)/4))+1";
    cout << "- Nesting depth of '" << s1 << "' is " << nestingDepth(s1) << endl;

    string s2 = "(1)+((2))+(((3)))";
    cout << "- Nesting depth of '" << s2 << "' is " << nestingDepth(s2) << endl;

    string s3 = "()(())((()()))";
    cout << "- Nesting depth of '" << s3 << "' is " << nestingDepth(s3) << endl;

    return 0;
}
