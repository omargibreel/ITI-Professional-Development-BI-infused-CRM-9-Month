#include <iostream>
//2-class Stack
///int*arr,int size,int tos ,static counter
///ctor() cout
///ctor(size) cout
///dest()  for loop -1 then delete [] arr then cout
///push,pop ,isfull,isempty


///ViewStack(Stack param)
//as standalone and friend fn

//in main write exactly
//Stack s1(10);
//push 4 or 6 times

//ViewStack(s1); //runs successfully
//ViewStack(s1); //fail
//Why? tomorrow isa

using namespace std;
class Stack
{
    ///int*arr,int size,int tos

    private:
        int *arr;
        int tos;
        int size;
        static int ctr;

    ///ctor() cout
    ///ctor(size) cout

    public:
        Stack()
        {
            ctr++;
            tos=0;
            size=5;
            arr=new int[size];
            cout<<"ctor called"<<endl;
        }
        Stack(int _size)
        {
            ctr++;
            tos=0;
            size=_size;
            arr=   new int[size];
            cout<<"Ctor Called"<<endl;
        }
        static int GetCounter()
        {
            return ctr;
        }
        ///dest()  for loop -1 then delete [] arr then cout
        ~Stack()
        {
            for(int i=0 ; i<size ; i++)
            {
                arr[i]=-1;
            }
            delete[] arr;
            cout<<"Destructor Called"<<endl;
            ctr--;
        }

        ///push,pop ,isfull,isempty
        void Push(int value)
        {
            if(!IsFull())
            {
                arr[tos]=value;
                tos++;
            }
            else
            {
                cout<<"FULL \n";
            }
        }
        int Pop()
        {
            int result=-1234;
            if(!IsEmpty())
            {
                tos--;
                result=arr[tos];
            }
            else
            {
                cout<<"empty stack \n";
            }
            return result;
        }
        int IsFull(){return tos==size;}
        int IsEmpty(){return tos==0;}


///ViewStack(Stack param)
///as standalone and friend fn
friend void ViewStack(Stack _stack);

};
void ViewStack(Stack _stack)
{
    for(int i=0 ; i<_stack.tos;i++)
    {
        cout<<_stack.arr[i]<<", ";
    }
    cout<<endl;
}
int Stack::ctr = 0;




int main()
{
    Stack s1(10);
    Stack s2(10);
    Stack s3(10);

        for(int i =0 ; i<6;i++)
    {
        s1.Push(i);
    }
ViewStack(s1); //runs successfully
cout<<"Stack Counter = "<<Stack::GetCounter()<<endl;
ViewStack(s1); //fail

//Stack s1(10);
//push 4 or 6 times


    return 0;
}
