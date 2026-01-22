#include <iostream>
#include<string.h>
using namespace std;


class Employee{
public:
    char name[20];
    float salary;
    int id;
    Employee* left;
    Employee* right;

    Employee(){
        id=0;
        strcpy(name,"no Name");
        salary=1000;
        left=right=NULL;
    }
    Employee(int _id, char _name[20],float _salary){
        id =_id;
        strcpy(name,_name);
        salary=_salary;
        left=right=NULL;

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

class BST {
public:
    Employee* root;
    BST()
    {
        root=NULL;
    }
    Employee* insert(Employee* r , Employee* node){
        // base case دي اللي بتوقف الريكيرجن
        // حسبي الله و نعم الوكيل في ال recursion
        if(r==NULL)
            r=node;
        else if(node->id < r->id)
            r->left=insert(r->left,node);
        else
            r->right =insert(r->right, node);

        return r;
    }

    void insert(Employee* node) {
        root=insert(root, node);
    }

    void preOrder(Employee* r) { // Root Lift Right
        if(r==NULL)
            return;
        r->printEmployee();
        preOrder(r->left);
        preOrder(r->right);
    }
    void inOrder(Employee* r){  // Left Root Right
        if(r == NULL)
            return;
        inOrder(r->left);
        r->printEmployee();
        inOrder(r->right);
    }
    void postOrder(Employee* r){  // Left Right Root
        if(r == NULL)
            return;
        postOrder(r->left);
        postOrder(r->right);
        r->printEmployee();
    }

    Employee* search(Employee* r , Employee* node) {
        if(r==NULL)
            return NULL;
        else if(r->id==node->id)
            return r;
        else if(r->id>node->id)
            return search(r->left,node);
        else
            return search(r->right,node);
    }

    int search(Employee* node) {
        Employee* result = search(root,node);
        if(result==NULL)
            return 0;
        else
            return 1;
    }

    Employee* findMin(Employee* r) {
        if(r==NULL)
            return NULL;
        else if(r->left==NULL)
            return r;
        else
            return findMin(r->left);
    }
    Employee* findMax(Employee* r) {
        if(r==NULL)
            return NULL;
        else if(r->right==NULL)
            return r;
        else
            return findMax(r->right);
    }

    Employee* dlt(Employee* r, Employee* node) {
        if(r==NULL)  // Empty tree
            return NULL;

        if(node->id > r->id) { // item exists in left sub tree
            r->right = dlt(r->right,node);
        }
        else if(node->id < r->id) { // item exist in right sub tree
            r->left = dlt(r->left,node);
        }
        else {
            if(r->left==NULL && r->right==NULL)  // leaf node
                r = NULL;
            else if(r->left != NULL && r->right == NULL) // one child on the left
            {
                r->id = r->left->id;
                delete r->left;
                r->left=NULL;
            }
            else if(r->left == NULL && r->right != NULL) // one child on the right
            {
                r->id = r->right->id;
                delete r->right;
                r->right=NULL;
            }
            else {
                Employee* maxLeft = findMax(r->left);
                r->id = maxLeft->id;
                strcpy(r->name, maxLeft->name);
                r->salary = maxLeft->salary;
                r->left = dlt(r->left, maxLeft);
            }
        }
        return r;
    }
    int getTreeHeight(Employee* r) {
        if (r == NULL)
            return 0;

        int leftHeight = getTreeHeight(r->left);
        int rightHeight = getTreeHeight(r->right);

        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    BST btree;
    Employee* e1 = new Employee(45, "Emp45", 450);
    Employee* e2 = new Employee(15, "Emp15", 150);
    Employee* e3 = new Employee(79, "Emp79", 790);
    Employee* e4 = new Employee(90, "Emp90", 900);
    Employee* e5 = new Employee(10, "Emp10", 100);
    Employee* e6 = new Employee(55, "Emp55", 550);
    Employee* e7 = new Employee(12, "Emp12", 120);
    Employee* e8 = new Employee(20, "Emp20", 200);
    Employee* e9 = new Employee(50, "Emp50", 500);

    btree.insert(e1);
    btree.insert(e2);
    btree.insert(e3);
    btree.insert(e4);
    btree.insert(e5);
    btree.insert(e6);
    btree.insert(e7);
    btree.insert(e8);
    btree.insert(e9);

    cout << "Tree Height = " << btree.getTreeHeight(btree.root) << endl;

    cout << "\n=== InOrder Before Deletions ===\n";
    btree.inOrder(btree.root);

    // delete leaf (12)
    Employee k1(12, "", 0);
    btree.root = btree.dlt(btree.root, &k1);

    cout << "\n=== InOrder After deleting 12 (Leaf) ===\n";
    btree.inOrder(btree.root);

    // delete one-child node (55)
    Employee k2(55, "", 0);
    btree.root = btree.dlt(btree.root, &k2);

    cout << "\n=== InOrder After deleting 55 (one child) ===\n";
    btree.inOrder(btree.root);

    // delete two-children node (15)
    Employee k3(15, "", 0);
    btree.root = btree.dlt(btree.root, &k3);

    cout << "\n=== InOrder After deleting 15 (two children) ===\n";
    btree.inOrder(btree.root);

    // delete root (45)
    Employee k4(45, "", 0);
    btree.root = btree.dlt(btree.root, &k4);

    cout << "\n=== InOrder After deleting 45 (root) ===\n";
    btree.inOrder(btree.root);



    return 0;
}
