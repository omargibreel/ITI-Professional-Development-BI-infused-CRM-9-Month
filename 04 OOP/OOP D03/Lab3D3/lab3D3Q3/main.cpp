#include <iostream>

using namespace std;

int main()
{
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



  cout<<"which number you want to search"<<endl;
        int numIndx;
        cin>>numIndx;
        for(int i=0; i<n;i++){
                if(numIndx==arr[i]){
                        cout<<"number at index => "<<i<<endl;
                break;
                }
        }


//which number you want to search
///4
//done at index 3

    return 0;
}
