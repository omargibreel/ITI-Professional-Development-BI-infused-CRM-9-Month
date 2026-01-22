#include <iostream>
#include <string.h>
using namespace std;

class Employee{
public:
char name[20];
float salary;
int id;
    Employee* next;
    Employee* prev;

    Employee(){
        id=0;
        strcpy(name,"no Name");
        salary=1000;
        next=prev=NULL;
    }
    Employee(int _id, char _name[20],float _salary){
        id =_id;
        strcpy(name,_name);
        salary=_salary;
        next=prev=NULL;
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
        cout<<"Id: "<<id<<" Name: "<<name<<" Salary: "<<salary<<endl;
    }
};


class LinkedList{
Employee* head;
Employee* tail;
public:
int size;
LinkedList(){
head=tail=NULL;
size=0;
}
    int isEmpty() {
        return (head==NULL);
    }
    void insertFirst(Employee* node){
        if(isEmpty()){
            node->next=NULL;
            node->prev=NULL;
            head=tail=node;
        }
        else{
            head->prev=node;
            node->next=head;
            node->prev=NULL;
            head=node;
        }
        size++;
    }
    void insertLast(Employee* node){
        if(isEmpty())
            insertFirst(node);
        else{
            tail->next=node;
            node->prev=tail;
            node->next=NULL;
            tail=node;
        }
        size++;
    }
    void insertAt(Employee* node , int id){
        Employee* temp =head;
        while(temp->id!=id&&temp->next!=NULL){
            temp=temp->next;
        }
        if(temp->id!=id){
              cout << "Employss with Id " << id << " not found.\n";
              return;
        }
        if(temp==head){
            insertFirst(node);
            return;
        }
        if(temp==tail){
            insertLast(node);
            return;
        }
        if(temp->next!=NULL){
            node->next=temp;
            node->prev=temp->prev;
            if(temp->prev)
                temp->prev->next=node;
            temp->prev=node;
        size++;
        }
    }

    void deleteFirst(){
        if(isEmpty()){
            cout<<"List is Empty \n";
            return;
        }
        Employee* temp=head;
         if(size==1)
        {
            head=tail=NULL;
        }
        else{
        head=head->next;
        head->prev=NULL;
        }
        delete temp;
        size--;
    }
    void deleteLast()
    {
        if(isEmpty()){
            cout<<"List is Empty \n";
            return;
        }

        Employee* temp= tail;
        if(size==1)
        {
            head=tail=NULL;
        }
        else
        {
            tail =tail->prev;
            tail->next= NULL;
        }
        size--;
        delete temp;
    }

    void deleteAt(int id) {
    if (isEmpty()) {
        cout << "List is Empty\n";
        return;
    }
    Employee* temp = head;
    while (temp && temp->id != id) {
        temp = temp->next;
    }
    if (!temp) {
        cout << "Employee with Id " << id << " not found.\n";
        return;
    }
    if (temp == head) {
        deleteFirst();
        return;
    }
    if (temp == tail) {
        deleteLast();
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    size--;
}

    void display(){
            Employee* temp=head;
            while(temp){
                temp->printEmployee();
                temp=temp->next;
            }
        }

};

class Stack:public LinkedList{
public:
void Push(Employee* node)
    {
        insertFirst(node);
    }
    void pop()
    {
        deleteFirst();
    }
};
int main() {
    Stack stk;

    Employee* e1 = new Employee(1, "Ali", 5000);
    Employee* e2 = new Employee(2, "Mona", 6000);
    Employee* e3 = new Employee(3, "Omar", 7000);

    stk.Push(e1);
    stk.Push(e2);
    stk.Push(e3);
    cout<<stk.size;

    cout << "Stack after Push:\n";
    stk.display();

    cout << "\nPop top element:\n";
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();

    stk.display();

    return 0;
}
