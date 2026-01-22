
 #include <iostream>
 #include <stdlib.h>
 #include <windows.h>
using namespace std;
void gotoxy( int column, int row )
{
     COORD coord;
     coord.X = column;
     coord.Y = row;
     SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
 }

int main()
{
    int size;
    do{
            cout<<"Add Your size"<<endl;
        cin>>size;
    }
    while(size%2!=1);
    int col;
    int row;
    row=1;
    col=size/2 +1;   //3*3 =>2    5*5=>3
    //col 1 row 3    i 1 2
    for (int i = 1; i <=size*size; i++)
    {
        gotoxy(col*3,row*3);
        cout<<i;
        //adjust coordinates for next #
        if(i % size !=0)  //reminder
        {
            row--;
            col--;
            if(col<1){col=size;}
            if(row<1){row=size;}
        }
        else  //no reminder
        {
            row++;
        }
    }

    return 0;
}
