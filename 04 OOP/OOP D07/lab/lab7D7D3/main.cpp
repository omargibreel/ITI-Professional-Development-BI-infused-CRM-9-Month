#include <iostream>

//3-implement shift  queue

using namespace std;

class Queue
{
    int *arr;
    int capacity;
    int size;
    static int ctr;
public:
    Queue(int _capacity)
    {
        capacity=_capacity;
        arr=new int[capacity];
        size=0;
        ctr++;
        cout<<"ctor called"<<endl;
    }
    void Enqueue(int x)
    {
        if(size!=capacity)
            {
                arr[size++]=x;
            }
        else
            {
                cout<<"queue is full"<<endl;
            }
    }
    int dequeue()
    {
        if(size==0)
        {
             cout<<"queue is empty"<<endl ;
             return -1234;
        }

        else
            {
                int num = arr[size-1];
             for(int i=1; i<size; i++)
             {
                 arr[i-1]=arr[i];
             }
             size--;
            return num;
            }
    }
    int GetFront()
    {
        if(size==0)
        {
            cout<<"Queue is emptuy"<<endl;
            return -1234;
        }
        else return arr[0];

    }
    int GetRear()
    {
        if(size==0)
        {
            cout<<"Queue is emptuy"<<endl;
            return -1234;
        }
        else return arr[size-1];
    }
     ~Queue()
    {
        for(int i=0 ; i<capacity ; i++)
            {
                arr[i]=-1;
            }
        delete[] arr;
        ctr--;
        cout<<"Destructor Called"<<endl;
    }
    friend void ViewQueue(Queue _queue);

};
void ViewQueue(Queue _queue)
{
    cout << "Queue Elements: ";
    if (_queue.size == 0)
    {
        cout << "empty" << endl;
    }

    for (int i = 0; i < _queue.size; i++)
    {
        cout << _queue.arr[i] << " ";
    }
    cout << endl;
}

int Queue::ctr = 0;

int main()
{
    Queue q1(5);
        q1.dequeue();

    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);
    q1.Enqueue(4);
    q1.Enqueue(5);
    q1.Enqueue(5);

    cout<<q1.GetFront()<<endl;
    cout<<q1.GetRear()<<endl;
    cout<<q1.dequeue()<<endl;

        q1.Enqueue(19);

    ViewQueue(q1);
    ViewQueue(q1);
    return 0;
}
