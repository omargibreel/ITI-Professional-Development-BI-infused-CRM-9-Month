#include <iostream>
#include <cstring>
using namespace std;

struct Employee{
    int empNum;
    char fName[50];
    char lName[40] ;
    int salary;
};

int main()
{
    //7- pointer to struct of employee   ->
     Employee emp;

    emp.empNum=4;
    strcpy(emp.fName,"omar");
    strcpy(emp.lName,"osama");
    emp.salary=600000;

    Employee *ptr = &emp;

    ptr->salary=900000;
    strcpy((ptr->fName),"Omar");
    cout<<emp.salary<<endl;
    cout<<emp.fName;
    return 0;
}
