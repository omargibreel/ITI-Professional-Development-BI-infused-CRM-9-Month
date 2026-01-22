#include <iostream>

using namespace std;
void insertionSort(int arr[],int size)
{
    // 0  1  2  3  4
    // 8  5  4  2  3           current = 5    arr[j] =8     if Arr[j]>current then swap
    // 2  3  4  5  8

    // 5  8  4  2  3
    for(int i=1; i<size;i++)
    {
        int current = arr[i];
        int j;
        for(j=i-1; j>=0 && arr[j]>current ; j--)
        {
            arr[j+1]=arr[j];
        }

        arr[j+1]=current;
    }
}
int main()
{
    int arr[] = { 12, -11, 13, 5, 6 };
    insertionSort(arr,5);
    for(int i = 0 ; i< 5 ;i++)
        {
            cout<<arr[i]<< " ";
        }
    return 0;
}



/*                                  cost        time
int i = 1;                            1           1
int sum = 0;                          1           1
while(i<=n)  //3                         1           n+1
{
    int j = 1 ;                       1           n
    while(j<=n) //3 n+1                     1             n(n+1) => n^2+n
    {
        sum+=i;                       2           n^2
        j+=1                          2           n^2
    }
    i+=1;                             2            n
}
*/         // total n^2
