#include <iostream>
using namespace std;

class employee{
	double salary;
	public :
		string name;
		char gender;
		int empID;
		
		void salary_set(double s){
			salary = s;
		}
		void salary_disp(){
			cout << "Salary : " << salary << endl;
		}
};

int main() {
    
    employee e1;
    e1.name = "Rahul";
    e1.gender = 'M';
    e1.salary_set(15000);
    e1.empID = 1;
    
    cout << "Name : " << e1.name << endl;
    cout << "Gender : " << e1.gender << endl;
    e1.salary_disp();
    cout << "EmpID : " << e1.empID << endl;
    
    cout << "Address of the salary variable : " << &e1.empID << endl;
    
    e1.salary_set(50000);
    e1.salary_disp();
    
    return 0;
}
