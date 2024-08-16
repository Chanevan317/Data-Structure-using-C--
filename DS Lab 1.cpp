#include <iostream>
#include <string>

int main(){
	
	std::string name, surname;
	char initial;
	
	std::cout << "Enter the name: ";
	std::cin >> name;
	std::cout << "Enter the surname: ";
	std::cin >> surname;
	std::cout << "Enter the initial: ";
	std::cin >> initial;
	
	std::cout << "Name: " << name << std::endl;
	std::cout << "Surname: " << surname << std::endl;
	std::cout << "Initial: " << initial << std::endl;
	
	
	int number;
	std::cout << "Enter a number : ";
	std::cin >> number;
	if(number > 0){
		std::cout << "The number is positive";
	}else if (number == 0){
		std::cout << "The number is zero";
	}else if (number < 0){
		std::cout << "The number is negative";
	}
	
	return 0;
}

