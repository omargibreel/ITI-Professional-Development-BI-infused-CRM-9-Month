#include <iostream>
#include <string.h>
using namespace std;

// Employee Class
class Employee {
public:
    char name[20];
    float salary;
    int id;
    Employee(int _id, char _name[],int _salary)
    {
        id =_id;
        strcpy(name,_name);
        salary=_salary;
    }
    Employee(const Employee &oldEmp)
    {
        id=oldEmp.id;
        salary=oldEmp.salary;
        strcpy(name,oldEmp.name);
    }
    int getId()
    {
        return id;
    }
    void printEmployee()
    {
        cout<<"Code: "<<id<<" Name: "<<name<<" Salary: "<<salary<<endl;
    }
    ~Employee(){};
};

template <typename T>
class Node
{
public:
    T* data;
    Node<T>* nxt;
    Node<T>* prev;

    Node(T*pItem)
    {
        data = pItem;
        nxt =NULL;
        prev = NULL;
    }
};

template<typename T>
class LinkedList
{
public:
    Node<T>* head;
    Node<T>*tail;
    int size;
    LinkedList()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }
    void addLast(T* pItem)
    {
        Node<T>* newNode = new Node<T>(pItem);
        if(!head)
        {
            head=tail=newNode;
        }
        else
        {
            tail->nxt=newNode;
            newNode->prev=tail;
            tail = newNode;
        }

        size++;
    }
    void addFirst(T*pItem)
    {
        Node<T>* newNode = new Node<T>(pItem);
        if(!head)
        {
            head=tail=newNode;
        }
        else
        {
            newNode->nxt = head;
            newNode->prev =NULL;
            head->prev= newNode;
            head=newNode;
        }

        size++;
    }

    void addAt(T*pItem,int pos)
    {
        if(pos<=0)
            addFirst(pItem);
        else if(pos>=size)
        {
            addLast(pItem);
        }
        else
        {
            Node<T>* newNode = new Node<T>(pItem);
            Node<T>*current = head;
            for(int i=0; i<pos;i++)
            {
                current=current->nxt;
            }
            newNode->nxt=current;
            newNode->prev=current->prev;
            current->prev->nxt = newNode;
            current->prev=newNode;

            size++;
        }
    }

    void display()
    {
        Node<T>* current = head;
        int index = 0;
        while(current)
        {
            current->data->printEmployee();
            current = current->nxt;
            index++;
        }

        cout << "\n\n";
    }

};
   /* void SortById(LinkedList emp[])
    {
        for(int i =0; i<emp.size; i++)
        {
            for(int j = 0 ; j<size-i-1; j++)
            {
                if(emp[j].dat>emp[j+1].id)
                {
                    Employee temp = emp[j];
                    emp[j]=emp[j+1];
                    emp[j+1]=temp;
                }
            }
        }
    }*/

int main()
{
    LinkedList<Employee> linked;
    Employee* e1 = new Employee(1, "Omar", 5000);
    Employee* e2 = new Employee(2, "nasser", 6000);
    Employee* e3 = new Employee(3, "mohanad", 7000);
    Employee* e4 = new Employee(4, "saaaaaaaaaaaa", 8000);
    Employee* e5 = new Employee(5, "pppppppp", 9000);

    linked.addFirst(e1);
    linked.addFirst(e2);
    linked.addLast(e1);
    linked.addFirst(e3);

    linked.addAt(e5,3);


    linked.display();

    return 0;
}
