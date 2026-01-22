#include <iostream>

using namespace std;

int main()
{

    //2- pointer to array  read and write   3 ways
    int arr[]={1,2,3,4,5};
    int *ptr;

    // Way V1
    ptr = arr;
    cout<<"first way --------------------------------\n";


    for(int i =0;i<5;i++){
    cout<<*ptr<<"\n";
    ptr++;
    }

    cout<<"Second way ---------------------------------- \n";
    ptr =arr;
       for(int i =0;i<5;i++){
    cout<<*(ptr+i)<<"\n";
    }


    cout<<"Third way ---------------------------------- \n";

    for(int i =0;i<5;i++){
    cout<<ptr[i]<<"\n";
    }

    return 0;
}
