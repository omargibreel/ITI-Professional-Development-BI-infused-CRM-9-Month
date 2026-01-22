#include <iostream>

using namespace std;

int main()
{
    //3- pointer to pointer of integer Write ONLY
    int x=10;
    int *ptr=&x;
    int **ptrToPtr=&ptr;
    cout<<"Before "<<x<<endl;
    *(*ptrToPtr)*=15;
    cout<<x;
    return 0;
}
