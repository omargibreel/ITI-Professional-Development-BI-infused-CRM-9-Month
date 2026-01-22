#include <iostream>

using namespace std;

int main()
{

    ///////////////////////////////////////////////////
///lab assignments

////////////////////
///1,3,5,7,8,10,12     31days
///4,6,9,11           30 days
///2      28,29 leap year    2000,2004,2008,2020,2024

///while ->   do while

///1- Birthdate
///plz enter your year from 1980->2025
//1900
///plz enter your year from 1973->2023
//1900
///plz enter your year from 1973->2023
//2000
///plz enter your month 1-12
//22
///plz enter your month
//23
///plz enter your month
//2
///plz enter your day
//31
///plz enter your day
//32
///plz enter your day
//32
///plz enter your day
//29


///you're 22y  3 months and 5 days

int currentday=20;
int currentmonth=10;
int currentyear=2025;

int day,month,year;

    do{
        cout<<"plz enter your year from 1980->2025"<<endl;
        cin>>year;

    }while(year>currentyear || year<1980);

if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
    do{
        cout<<"Plz Enter your Month"<<endl;
        cin>>month;
    }while(month<1 || month > 12);
if(month==2){
    do{
        cout<<"Plz Enter your Day"<<endl;
        cin>>day;
    }while(day<1 || day>29);
}
else {
    do{
        cout<<"Plz Enter your Day"<<endl;
        cin>>day;
    }while(day<1 || day>31);
}
}

else{
        do{
        cout<<"Plz Enter your Month"<<endl;
        cin>>month;
}
while(month<1 || month > 12);
    if(month==2){
  do{
        cout<<"Plz Enter your Day"<<endl;
        cin>>day;
    }while(day<1 || day>28);
    }
    else{

            ///1,3,5,7,8,10,12     31days
///4,6,9,11           30 days
if (month == 1 || month == 3 || month == 5 || month == 7 ||
    month == 8 || month == 10 || month == 12){
           do{
        cout<<"Plz Enter your Day"<<endl;
        cin>>day;
    }while(day<1 || day>31);
    }
    else{
         do{
        cout<<"Plz Enter your Day"<<endl;
        cin>>day;
    }while(day<1 || day>30);

    }
    }
}








int NumOfYears, NumOfMonths, NumOfDays;

if (currentday < day)
{
    currentday += 30;
    currentmonth -= 1;
}
NumOfDays = currentday - day;


if (currentmonth < month)
{
    currentmonth += 12;
    currentyear -= 1;
}
NumOfMonths = currentmonth - month;


NumOfYears = currentyear - year;

cout<<"You're "<<NumOfYears<<"y "<<NumOfMonths<<" months and "<<NumOfDays<<" days."<<endl;
    return 0;
}

