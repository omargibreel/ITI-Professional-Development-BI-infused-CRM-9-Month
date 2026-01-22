#include <iostream>
#include <string.h>

using namespace std;

class Employee
{
public:
   int id;
    char firstName[20];
    int salary;
    Employee(int _id, char _firstName[],int _salary)
    {
        id =_id;
        strcpy(firstName,_firstName);
        salary=_salary;
    }
    Employee(const Employee &oldEmp)
    {
        id=oldEmp.id;
        salary=oldEmp.salary;
        strcpy(firstName,oldEmp.firstName);
    }
    ~Employee(){};
};

  void SortById(Employee emp[], int size)
    {
        for(int i =0; i<size; i++)
        {
            for(int j = 0 ; j<size-i-1; j++)
            {
                if(emp[j].id>emp[j+1].id)
                {
                    Employee temp = emp[j];
                    emp[j]=emp[j+1];
                    emp[j+1]=temp;
                }
            }
        }
    }

int main()
{
    Employee emp[3]= {
                Employee(3,"omar",30000),
                Employee(6,"nasser",25000),
                Employee(1,"mohaned",20000)
                };
    cout<<"before sorting "<<endl;
    for(int i=0;i<3;i++)
    {
        cout<<"emp id = "<<emp[i].id<<" and Name : "<<emp[i].firstName<<" and salary = "<<emp[i].salary<<endl;
    }
    SortById(emp,3);
    cout<<"\n \n\n";
    cout<<"after sorting "<<endl;
     for(int i=0;i<3;i++)
    {
        cout<<"emp id = "<<emp[i].id<<" and Name : "<<emp[i].firstName<<" and salary = "<<emp[i].salary<<endl;
    }
    return 0;
}
