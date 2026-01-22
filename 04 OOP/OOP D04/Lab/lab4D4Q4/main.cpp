#include <iostream>

using namespace std;


void swapByAddress(int *left,int *right){
        int temp;
        temp = *left;
        *left = *right;
        *right = temp;
    }
    void swapByValue(int left,int right){
        int temp;
        temp = left;
        left = right;
        right = temp;
    }


int main()
{
    //4- pass by value/address    swap

    // passing by value
    int x=10,y=5;
    swapByValue( x, y);
    cout<<"x="<<x<<endl;
    cout<<"y="<<y<<endl;
    // passing by address
//    int x=10,y=5;
//    swapByAddress(&x,&y);
//    cout<<"After Swap\n";
//    cout<<"x="<<x<<endl;
//    cout<<"y="<<y<<endl;

    return 0;
}
