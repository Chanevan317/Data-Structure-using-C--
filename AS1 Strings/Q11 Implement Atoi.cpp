#include <iostream>
#include <cmath>
using namespace std;

int atoi(string s)
{
    int integer = 0;
    bool neg = false;
    int n = s.length();
    int i = 0;

    while (i < n) 
    {
        // Break loop if it is not a number or "-" or " "
        if (s[i] < '0' || s[i] > '9')
        {
            if (s[i] != ' ' && s[i] != '-')
            {
                break;
            }
            
        }
        // Ignore spaces
        if (s[i] == ' ')
        {
            i++;
        }
        // Check for negative sign
        if (i < n && s[i] == '-') {
            neg = true;
            i++;
        }
        // Convert characters to integer
        if (i < n && s[i] >= '0' && s[i] <= '9') {
            integer = integer * 10 + (s[i] - '0');
        }

        i++;
    }
    // Make the integer negative if negative sign present
    if (neg) {
        integer = -integer;
    }
    
    return integer;
}

int main()
{
    cout << "Converting String into integer(atoi) : " << endl; 

    string s1 = "42";
    cout << "- Converted string '" << s1 << "' into integer : " << atoi(s1) << endl;

    string s2 = " -042";
    cout << "- Converted string '" << s2 << "' into integer : " << atoi(s2) << endl;

    string s3 = "1337c0d3";
    cout << "- Converted string '" << s3 << "' into integer : " << atoi(s3) << endl;

    string s4 = "words and 987";
    cout << "- Converted string '" << s4 << "' into integer : " << atoi(s4) << endl;

    return 0;
}