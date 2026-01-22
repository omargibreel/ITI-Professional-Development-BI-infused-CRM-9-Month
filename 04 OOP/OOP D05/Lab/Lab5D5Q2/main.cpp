#include <iostream>
using namespace std;

int main() {
int row = 3;
 int col=4;
 int *ptr[row];

for(int i=0;i<row;i++){
    ptr[i]=new int[col];
}
  for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<"plz enter your num of ["<<i<<"]"<<"["<<j<<"]"<<endl;
            cin>>ptr[i][j];
        }
    }

     for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<"["<<i<<"]"<<"["<<j<<"] = "<<ptr[i][j]<<endl;

        }
    }

    return 0;
}
