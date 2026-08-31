#include <iostream>
#include <string>
using namespace std;
class Teacher{
//properties (attributes)
public:
string name;
string dept;
string subject;
double salary;

//methods (member functions)
void changeDept(string newDept){
    dept = newDept;
}
};
int main(){
Teacher t1;
t1.name ="Sharik Dhiman";
t1.subject ="DESIGN";
t1.dept ="Computer science";
t1.salary= 250000.00;
cout<<t1.name<<endl<<t1.subject<<endl<<t1.salary<<endl;

cout << "The Old Department is :" << t1.dept << endl;
t1.changeDept("AIML");
cout << "The New Department is :" << t1.dept << endl;
    return 0;
}