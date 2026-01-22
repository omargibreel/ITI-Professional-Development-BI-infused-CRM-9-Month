#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //8- fname, lname -> fullname
        char fName[50]="omar";
        char lName[50]="osama";
        char fullName[100] ;
        strcpy(fullName,fName);
        strcat(fullName," ");
        strcat(fullName,lName);
        cout<<fullName;
    return 0;
}
