#include <iostream>

using namespace std;
int* returnArr()
{
    static int result[5]={1,2,3,4,5};
    return result;
}

int main()
{
    //6- return [] as return type[not supported][compiler error]
    //and return pointer as a return type


    int *ptr=returnArr();
    for(int i =0; i<5;i++){
        cout<<*(ptr+i)<<endl;
    }

    return 0;
}
