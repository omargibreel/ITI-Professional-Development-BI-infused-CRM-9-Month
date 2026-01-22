#include <iostream>
//2- stack
///cpy ctor [MUST]
///=operator [MUST]
///Stack Reverse(){}

///bonus    s1==s2
///bonus    s3=s1+s2;

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

        ///cpy ctor [MUST]
        Stack(const Stack& oldStack)
        {
            tos=oldStack.tos;
            size=oldStack.size;
            arr=new int[size];
            for(int i=0; i<tos;i++)
            {
                arr[i]=oldStack.arr[i];
            }
            cout<<"copy ctor \n";
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

        ///=operator [MUST]

        Stack& operator = (const Stack&right)
        {
            Stack Temp ;
            delete[]arr;   ///avoid memory leakage
            tos=right.tos;
            size=right.size;
            arr=new int[size];
            for (int i = 0; i < tos; i++)
            {
                arr[i]=right.arr[i];
            }
        return *this;
        }

        ///Stack Reverse(){}
        Stack Reverse()
        {
            Stack result(size);
            for(int i =tos-1; i>=0;i--)
            {
                result.Push((arr[i]));
            }
            return result;
        }


///bonus    s1==s2
        int operator==(const Stack& right)
        {
            if(tos!=right.tos)
                return 0;
            int flag;
            int* freq = new int[tos] {0};
            for(int i=0 ; i<tos; i++){
                    flag =0;
               for(int j=0 ; j<tos; j++){
                    if(arr[i]==right.arr[j]&&freq[j]==0){
                        freq[j]=1;
                        flag =1;
                        break;
                    }
                }
                if(flag==0)
                {
                    delete[] freq;
                    return flag;
                }
            }
            delete[] freq;
            return 1;

        }
///bonus    s3=s1+s2;
 Stack operator+(const Stack& right)
    {
        int _size=size+right.size;
        Stack result(_size);
        for(int i =0;i<tos;i++) result.Push(arr[i]);
            for(int i =0;i<right.tos;i++)result.Push(right.arr[i]);
        return result;
    }

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
//    Stack s1(10);
//    Stack s2(10);
//    Stack s3(10);
//
//        for(int i =0 ; i<6;i++)
//    {
//        s1.Push(i);
//    }
//ViewStack(s1);
//cout<<"Stack Counter = "<<Stack::GetCounter()<<endl;
//ViewStack(s1); //fail

//Stack s1(10);
Stack s1(5),s2(5);
s1.Push(1);
s1.Push(2);
s1.Push(1);
s1.Push(3);

s2.Push(1);
s2.Push(1);
s2.Push(2);
s2.Push(3);


int x =s1==s2;
cout<<"Check in s1 = s2 ==>"<<x<<endl;
Stack s4 ;
s4 = s2.Reverse();
cout<<"s2";
ViewStack(s2);
cout<<endl;
cout<<"reverve";
ViewStack(s4);


Stack s3;
s3=s1+s2;
ViewStack(s3);



    return 0;
}
