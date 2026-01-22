#include <iostream>

using namespace std;

int main()
{
    //5-2D Array
//array [3][4]
//calculate average of columns
//int avg[4]

//int avg[4]


//-2 7 11 0 19 22 -8 5 4 16 24 -12

cout<<"Hello plz enter your 2D array elements \n";

int arr[3][4];
for(int i=0; i<3;i++){
        for(int j =0;j<4;j++){
                cout<< "Arr[" << i << "]" <<"[" << j << "]";
            cin>>arr[i][j];
        }
        cout<<"\n";
}

for(int i=0; i<3;i++){
        for(int j =0;j<4;j++){
            cout<<"  "<<arr[i][j]<<"  ";
        }
        cout<<endl;
}

int avg[4]={0};
for(int j =0; j<4;j++){
    for(int i=0; i<3;i++){
        avg[j]+=arr[i][j];
    }
}

for(int i=0;i<4;i++){
    cout<<avg[i]/3<<" ";
}
    return 0;
}
