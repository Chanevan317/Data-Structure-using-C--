#include <iostream>
#include <cmath>
using namespace std;

int romanToInteger(string roman)
{
    int integer = 0;
    int i = roman.length()-1;

    while (i >= 0)
    {
        // If it is I
        if(roman[i] == 'I') integer ++;
        // If it is V or IV
        else if(roman[i] == 'V')
        {
            if(i > 0 && roman[i-1] == 'I') // If it is IV
            {
                integer += 4; 
                i--;
            } 
            else // If it is not IV but V
            {
                integer += 5;
            } 
        }
        // If it is X or IX
        else if(roman[i] == 'X')
        {
            if(i > 0 && roman[i-1] == 'I') // If it is IX
            {
                integer += 9; 
                i--;
            } 
            else // If it is not IX but X
            {
                integer += 10;
            } 
        }
        // If it is L or XL
        else if(roman[i] == 'L')
        {
            if(i > 0 && roman[i-1] == 'X') // If it is XL
            {
                integer += 40; i--;
            } 
            else // If it is not XL but L
            {
                integer += 50;
            } 
        }
        // If it is C or XC
        else if(roman[i] == 'C')
        {
            if(i > 0 && roman[i-1] == 'X') // If it is XC
            {
                integer += 90; 
                i--;
            } 
            else // If it is not XC but C
            {
                integer += 100;
            } 
        }
        // If it is D or CD
        else if(roman[i] == 'D')
        {
            if(i > 0 && roman[i-1] == 'D') // If it is CD
            {
                integer += 400; 
                i--;
            } 
            else // If it is not CD but D
            {
                integer += 500;
            } 
        }
        // If it is M or CM
        else if(roman[i] == 'M')
        {
            if(i > 0 && roman[i-1] == 'C') // If it is CM
            {
                integer += 900; 
                i--;
            }
            else // If it is not CM but M
            {
                integer += 1000;
            } 
        }

        i--;
    }


    // Better alternative from chatgpt
    /*int integer = 0;
    int length = roman.length();
    // Map Roman numeral characters to their integer values
    int valueMap[256] = {0}; // 256 for ASCII characters
    valueMap['I'] = 1;
    valueMap['V'] = 5;
    valueMap['X'] = 10;
    valueMap['L'] = 50;
    valueMap['C'] = 100;
    valueMap['D'] = 500;
    valueMap['M'] = 1000;
    for (int i = 0; i < length; i++) {
        // Current character value
        int currentValue = valueMap[roman[i]];
        
        // Next character value (if it exists)
        int nextValue = (i + 1 < length) ? valueMap[roman[i + 1]] : 0;

        // Determine whether to add or subtract
        if (currentValue < nextValue) {
            integer -= currentValue;
        } else {
            integer += currentValue;
        }
    }*/

    return integer;
}

string integerToRoman(int integer)
{
    string roman = "";
    
    while (integer >= 1000)
    {
        roman += "M";
        integer -= 1000;
    }
    while (integer >= 900)
    {
        roman += "CM";
        integer -= 900;
    }
    while (integer >= 500)
    {
        roman += "D";
        integer -= 500;
    }
    while (integer >= 400)
    {
        roman += "CD";
        integer -= 400;
    }
    while (integer >= 100)
    {
        roman += "C";
        integer -= 100;
    }
    while (integer >= 90)
    {
        roman += "XC";
        integer -= 90;
    }
    while (integer >= 50)
    {
        roman += "L";
        integer -= 50;
    }
    while (integer >= 40)
    {
        roman += "XL";
        integer -= 40;
    }
    while (integer >= 10)
    {
        roman += "X";
        integer -= 10;
    }
    while (integer >= 9)
    {
        roman += "IX";
        integer -= 9;
    }
    while (integer >= 5)
    {
        roman += "V";
        integer -= 5;
    }
    while (integer >= 4)
    {
        roman += "IV";
        integer -= 4;
    }
    while (integer >= 1)
    {
        roman += "I";
        integer -= 1;
    }
    
    return roman;
}

int main()
{
    // Roman to Integer
    cout << "Converting Roman to Integer : " << endl; 

    string s1 = "III";
    cout << "- " << s1 << " is " << romanToInteger(s1) << endl;

    string s2 = "LVIII";
    cout << "- " << s2 << " is " << romanToInteger(s2) << endl;

    string s3 = "MCMXCIV";
    cout << "- " << s3 << " is " << romanToInteger(s3) << endl;
  

    // Integer to Roman
    cout << endl << "Converting Integer to Roman : " << endl; 

    int i1 = 3;
    cout << "- " << i1 << " is " << integerToRoman(i1) << endl;
  
    int i2 = 58;
    cout << "- " << i2 << " is " << integerToRoman(i2) << endl;

    int i3 = 1994;
    cout << "- " << i3 << " is " << integerToRoman(i3) << endl;

    return 0;
}