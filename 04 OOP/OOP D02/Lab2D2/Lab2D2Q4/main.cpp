#include <iostream>

using namespace std;

int main()
{


///4-Calculator add,sub,,, as a functions
///plz enter #1
//2
//plz wnter #2
//3
//plz enter operator
//*

//2*3=6
//Continue ??? y or n
//y Enter

///plz enter #1
//5
//plz wnter #2
//10
//plz enter operator
//+
//5+10=15
//Continue ??? y or n
//n

//program end
char x = 'y';
do{
int num1, num2 ;
char oper;
cout<<"plz enter #1"<<endl;
cin>>num1;
cout<<"plz enter #2"<<endl;
cin>>num2;
cout<<"plz enter operator"<<endl;
cin>>oper;

switch(oper){
case '*':
    cout<<num1*num2<<endl;
    break;
case '+' :
    cout<<num1+num2<<endl;
        break;
case '-' :
    cout<<num1-num2<<endl;
        break;
case '/':
    cout<<num1/num2<<endl;
        break;
default :
    cout<<"wrong operator"<<endl;
}

cout<<"Continue ??? y or n"<<endl;
cin>>x;
}while(x=='y');
cout<<"program end";
    return 0;
}
