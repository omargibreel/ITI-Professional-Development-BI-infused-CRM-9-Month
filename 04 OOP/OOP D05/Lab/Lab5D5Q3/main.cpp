#include <iostream>

using namespace std;

int main()
{
     int row=3;
    int col=4;
    int ** ptrArr=new int*[row];

    for (int i = 0; i < 3; i++){
        ptrArr[i]=new int[col];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
              cout<<"plz enter your num of ["<<i<<"]"<<"["<<j<<"]"<<endl;
            cin>>ptrArr[i][j];
        }
    }


    delete[] ptrArr[0];
    delete[] ptrArr[1];
    delete[] ptrArr[2];
    delete[] ptrArr;

    return 0;
}
