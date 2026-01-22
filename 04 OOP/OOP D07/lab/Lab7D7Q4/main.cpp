#include <iostream>

//3-implement circular queue

using namespace std;

class Queue
{
    int *arr;
    int capacity;
    int size;
    int front;
    static int ctr;
public:
    Queue(int _capacity)
    {
        capacity=_capacity;
        arr=new int[capacity];
        size=0;
        front=0;
        ctr++;
        cout<<"ctor called"<<endl;
    }
    void Enqueue(int x)
    {
        if(size!=capacity)
            {
                int rear = (front+size)%capacity;
                arr[rear]=x;
                size++;
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
             int removedNum = arr[front];
             front=(front+1)%capacity;
             size--;
             return removedNum;
            }
    }
    int GetFront()
    {
        if(size==0)
            return -1234;
        else return arr[front];

    }
    int GetRear()
    {
        if(size==0)
            return -1234;
        int rear = (front+size-1)%capacity;
        return arr[rear];
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
        int index = (_queue.front + i) % _queue.capacity;
        cout << _queue.arr[index] << " ";    }
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
    cout<<q1.GetFront()<<endl;

        q1.Enqueue(19);

    ViewQueue(q1);
    ViewQueue(q1);
    return 0;
}
