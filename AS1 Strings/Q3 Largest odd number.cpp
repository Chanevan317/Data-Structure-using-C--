#include <iostream>
using namespace std;

string largestOddNumber(string nb) 
{
    for (int i = nb.size(); i >= 0; i--) 
    {
        if ((nb[i] - '0') % 2 != 0) // '0' in ASCII is 48
        {  
            return nb.substr(0, i + 1);  // Return largest odd number
        }
    }
    return ""; // If there is no odd number
}

int main()
{
    string nb1 = "52";
    cout << "Largest odd number in " << nb1 << " : " <<  largestOddNumber(nb1) << endl;
    string nb2 = "4206";
    cout << "Largest odd number in " << nb2 << " : " <<  largestOddNumber(nb2) << endl;
    string nb3 = "35427";
    cout << "Largest odd number in " << nb3 << " : " <<  largestOddNumber(nb3) << endl;
    return 0;
}