#include <iostream>
#include <string>
using namespace std;
class Teacher
{
    // properties (attributes)
private:
    double salary;

public:
    string name;
    string dept;
    string subject;

    // methods (member functions)
    void changeDept(string newDept)
    {
        dept = newDept;
    }
    // functions to use private values
    // setter
    void setSalary(double s)
    {
        salary = s;
    }
    // getter
    double getSalary()
    {
        return salary;
    }
};
int main()
{
    Teacher t1;
    t1.name = "Sharik Dhiman";
    t1.subject = "DESIGN";
    t1.dept = "Computer science";
    // setting the value of the salary
    t1.setSalary(250000.00);

    cout << t1.name << endl
         << t1.subject << endl;
    // printing salary value
    cout << t1.getSalary() << endl;

    cout << "The Old Department is :" << t1.dept << endl;

    t1.changeDept("AIML");

    cout << "The New Department is :" << t1.dept << endl;

    return 0;
}