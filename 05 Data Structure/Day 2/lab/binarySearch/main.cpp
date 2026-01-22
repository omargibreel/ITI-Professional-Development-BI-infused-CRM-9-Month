#include <iostream>
#include<string.h>
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

int BinarySearch(Employee arr[],int size,int check)
{
    int left = 0;
    int right = size - 1;
    while(left<=right)
    {
        int middle = (left+right)/2;
        if(check==arr[middle].id)
        {
            cout<<"employee at index ";
            return middle;
        }

        else if(arr[middle].id<check)
            left=middle+1;
        else
            right=middle-1;
    }
    cout<<"Employee not found !!!!!!!"<<endl;
    return -529895651;

}

int main()
{
     Employee employees[10] =
    {
        Employee(1, "Ali", 5000),
        Employee(2, "Omar", 5200),
        Employee(3, "Sara", 5300),
        Employee(4, "Mostafa", 5400),
        Employee(5, "Laila", 5500),
        Employee(6, "Yousef", 5600),
        Employee(7, "Nada", 5700),
        Employee(8, "Karim", 5800),
        Employee(9, "Hana", 5900),
        Employee(10, "Mariam", 6000)
    };
    int id;
    cout<<"plz enter the id you want to search \n";
    cin>>id;
    cout<<BinarySearch(employees,10,id);
    return 0;
}
