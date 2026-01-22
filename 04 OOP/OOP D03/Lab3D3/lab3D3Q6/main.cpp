#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;

int main()
{
    //8- read string from user
///and then print it reversly

///enter statement
///My name is Ali
//ilA si eman yM
//int length;
cout<<"enter length of your statememt"<<endl;
//cin>>length;
//length+=10;
cout<<"enter statement"<<endl;
char txt[10];
gets(txt);

for(int i=/*strlen(txt)*/10-1;i >=0 ;i--)cout<<txt[i];
    return 0;
}
