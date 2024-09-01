#include <iostream>
using namespace std;

class Employee 
{
    private:
        int empID;
        string name;
        char gender;
        double salary;

    public:
        Employee(int id, string nm, char gdr, double sal) 
            : empID(id), name(nm), gender(gdr), salary(sal) {}

        void display() const {
            cout << "- ID: " << empID << ", Name: " << name
                << ", Gender: " << gender << ", Salary: " << salary << endl;
        }

        void updateSalary(double newSalary) {
            salary = newSalary;
        }

        int getId(){
            return empID;
        }
};

int main() {
    Employee employees[10] = {
        Employee(1, "Alex", 'M', 50000),
        Employee(2, "Bob", 'M', 55000),
        Employee(3, "Cindy", 'F', 60000),
        Employee(4, "David", 'M', 45000),
        Employee(5, "Eugene", 'M', 70000),
        Employee(6, "Fiona", 'F', 52000),
        Employee(7, "Gerard", 'M', 48000),
        Employee(8, "Hugo", 'M', 53000),
        Employee(9, "Ian", 'M', 62000),
        Employee(10, "Joana", 'F', 56000)
    };

    // Update salaries for all employees
    for (int i = 0; i < 10; ++i) {
        int newSal;
        cout << "- New salary of the employee " << employees[i].getId() << " : ";
        cin >> newSal;
        employees[i].updateSalary(newSal);
    }

    // Display updated employee details
    cout << endl << "All employees details : " << endl;
    for (int i = 0; i < 10; ++i) {
        employees[i].display();
    }

    return 0;
}
