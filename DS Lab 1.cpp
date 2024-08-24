#include <iostream>
#include <string>
using namespace std;

int main(){
	
	string name, surname;
	char initial;
	
	cout << "Enter the name: ";
	cin >> name;
	cout << "Enter the surname: ";
	cin >> surname;
	cout << "Enter the initial: ";
	cin >> initial;
	
	cout << "Name: " << name << endl;
	cout << "Surname: " << surname << endl;
	cout << "Initial: " << initial << endl;
	
	
	int number;
	cout << "Enter a number : ";
	cin >> number;
	if(number > 0){
		cout << "The number is positive";
	}else if (number == 0){
		cout << "The number is zero";
	}else if (number < 0){
		cout << "The number is negative";
	}
	
	return 0;
}

