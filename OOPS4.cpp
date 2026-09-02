#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;   // Member variable of Person
    int age;       // Member variable of Person

    // Constructor
    // n and a are PARAMETERS (temporary variables that receive values)
    Person(string n, int a)
    {
        // this->name = member variable "name"
        // n = parameter received by constructor
        //
        // Meaning: store the value of n inside this object's name
        this->name = n;

        // this->age = member variable "age"
        // a = parameter
        //
        // Meaning: store the value of a inside this object's age
        this->age = a;
    }
};


class Student : public Person
{
public:
    int rollno;   // Member variable of Student

    // n, a and p are PARAMETERS
    //
    // n  -> name value
    // a  -> age value
    // p  -> roll number value
    //
    // Person(n, a) calls the PARENT CLASS constructor
    // and passes n and a to it.
    Student(string n, int a, int p) : Person(n, a)
    {
        // rollno = member variable
        // p = parameter
        //
        // Store p inside this object's rollno
        this->rollno = p;
    }

    void getInfo()
    {
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "rollno : " << rollno << endl;
    }
};


int main()
{
    // Values are passed to the Student constructor
    //
    // "Sharik Dhiman" -> n
    // 20              -> a
    // 177             -> p
    //
    // Then n and a are passed to Person:
    // Person(n, a)
    Student s1("Sharik Dhiman", 20, 177);

    s1.getInfo();

    return 0;
}