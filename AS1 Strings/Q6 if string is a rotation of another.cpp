#include <iostream>
using namespace std;

void rotateStringRight(string &str)
{
    int len = str.length()-1;
	int last_char = str[len];
    for(int i = len; i > 0; i--){
        str[i] = str[i-1];
    }
	str[0] = last_char;
}

string rotationOfAnotherString(string s, string goal) 
{
    int nS = s.length(), nG = goal.length();
    if(nS != nG) return "false";
    for(int i = 0; i < nS; i ++)
    {
        if(s == goal)
        {
            return "true";
        }
        rotateStringRight(s); // Rotate the string
    }
    return "false";
}

int main() {
    string s1 = "abcde", goal1 = "cdeab";
    cout << "Is '" << goal1 << "' the rotation of '" << s1 << "' ?\n" << "=> " << rotationOfAnotherString(s1, goal1) << endl;
    string s2 = "abcde", goal2 = "abced";
    cout << "Is '" << goal2 << "' the rotation of '" << s2 << "' ?\n" << "=> " << rotationOfAnotherString(s2, goal2) << endl;
    return 0;
}
