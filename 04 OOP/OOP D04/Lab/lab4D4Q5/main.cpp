#include <iostream>

using namespace std;

void PrintArrayPointer(int *arr,int _size)
{
    for (int i = 0; i < _size; i++)
    {
        cout<<*(arr+i) <<"  ";
    }
}
void PrintArray(int arr[],int _size)
{
    for (int i = 0; i < _size; i++)
    {
        cout<<arr[i]<<"  ";
    }
}

int main()
{
//5- pass array as input param []   ,pass pointer
int arr[5]{10,20,30,40,50};
int *ptr =arr;
PrintArray(arr,5);
PrintArrayPointer(ptr,5);
    return 0;
}
