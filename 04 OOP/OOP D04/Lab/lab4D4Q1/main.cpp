#include <iostream>

using namespace std;

int main()
{
    //1- pointer to integer  read & write
    int x = 5;
    int *ptr = &x;

    // read
    cout<<*ptr<<endl;

    //write
    *ptr=20;
    cout<<x;
    return 0;
}
