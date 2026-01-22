#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    ///Lab Assignments [separate project]

///Arrays of 10 places of integer int arr[10]
///Read ALL Data From user in Runtime
//XXX int arr[10]={1,2,3,4,5,6,7,8,9,0};

//1D Array
//1-Array min  and max value  |7|3|5|6|8|-1|-11|33|99| no built in fn
//2-Array sort    same array            |-11|-1|3|5|6||||||no built in fn
//3-search on array and return index
// |1|2|3|4|1|5|6|2|1|9|10|

//which number you want to search
///4
//done at index 3





cout<<"Hayyy proooooo"<<endl;
cout<<"give me size of your array"<<endl;
int n;
cin>>n;
cout<<"\n";

int arr[n];

for(int i=0; i<n;i++){
    cout<<"plz enter number "<<i+1<<"  :  " ;
    cin>>arr[i];
}
cout<<"\n";

cout<<"your array = [";
for(int i=0; i<n;i++){
        if(i==n-1){
            cout<<arr[i];
        }
        else{
            cout<<arr[i]<<" , ";
        }

}
cout<<"]"<<endl;


int min = INT_MAX;
int max = INT_MIN;
for(int i=0; i<n;i++){
    if(min>arr[i])min=arr[i];
    if(max<arr[i])max=arr[i];
}
cout<<"\n";

cout<<"And Maximum Num = "<<max<<" & Minimum Num = "<<min<<endl;


    return 0;
}
