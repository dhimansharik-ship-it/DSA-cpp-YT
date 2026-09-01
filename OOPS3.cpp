#include <iostream>
#include <string>
using namespace std;

class Teacher
{
private:
    double salary; // Data hiding

public:
    // Properties / Attributes
    string name;
    string dept;
    string subject;

    // Constructor
    Teacher()
    {
        cout << "This is a constructor line" << endl;
        subject = "Object Oriented Programming In C++";
    }

    // Method / Member Function
    void changeDept(string newDept)
    {
        dept = newDept;
    }

    // Setter
    void setSalary(double s)
    {
        salary = s;
    }

    // Getter
    double getSalary()
    {
        return salary;
    }
};

int main()
{
    // Creating object
    Teacher t1;

    // Assigning values
    t1.name = "Sharik Dhiman";
    t1.dept = "Computer Science";

    // Setting salary using setter
    t1.setSalary(250000.00);

    // Displaying name and subject
    cout << t1.name << endl;
    cout << t1.subject << endl;

    // Displaying salary using getter
    cout << t1.getSalary() << endl;

    // Display old department
    cout << "The Old Department is : " << t1.dept << endl;

    // Changing department
    t1.changeDept("AIML");

    // Display new department
    cout << "The New Department is : " << t1.dept << endl;

    return 0;
}