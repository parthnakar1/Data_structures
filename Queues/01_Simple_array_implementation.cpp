/* Queue, a linear data structure, follows FIFO(First In First Out). Queue here is implemented using arrays as data
   member in a class. Few basic functions are as follows:
   1. bool isEmpty(...) : It returns true if queue is empty.
   2. bool isFull(...) : It returns true if queue is full.
   3. void enqueue(...) : The data passed as parameter is added to queue from rear.
   4. int dequeue(...) : This function removes data at front of the queue i.e. the oldest data among all entries.
   5. int front(...) : The function returns element at front of the queue.
   6. int rear(...) : The function returns element at rear of the queue.
   **NOTE** : Queue implemented through array as data member of class has a disadvantage fixed size.
              The implementation uses technique of circular array.
*/
#include <iostream>
#include <limits.h>
# define Max 5
using namespace std;

class Queue
{
    public:
    int Front,Rear;
    int arr[Max];
    Queue()
    {
        Front = -1;
        Rear = -1;
    }
    bool isEmpty();
    bool isFull();
    void enqueue(int data);
    int dequeue();
    int front();
    int rear();
};

bool Queue::isEmpty()
{
    return (Front == -1 && Rear == -1);
}

bool Queue::isFull()
{
    return ((Rear + 1) % Max == Front);
}

void Queue::enqueue(int data)
{
    if(isFull())
    {
        cout << "Queue is full." << endl;
        return;
    }
    else if(isEmpty())
    {
        Front = 0, Rear = 0;            // Initialize Front = 0 and Rear = 0.
    }
    else
    {
        Rear = (Rear + 1) % Max;        // Rear should be incremented by 1 but this handles when rear reaches end
    }                                   // of array so that it is assigned correct value and not out of index.
    arr[Rear] = data;
}

int Queue::dequeue()
{
    if(isEmpty())
    {
        cout << "Queue is Empty." << endl;
        return INT_MIN;
    }
    int temp = arr[Front];
    if(Front == Rear)
    {
        Rear = -1, Front = -1;           // This condition is when queue has only 1 element. 
    }
    else
    {
        Front = (Front + 1) % Max;       // Front should be incremented by 1 but this helps when Front is
    }                                    // end of the array.
    return temp;
}

int Queue::front()
{
    if(isEmpty())
    {
        cout << "Queue is Empty." << endl;
        return INT_MIN;
    }
    return arr[Front];
}

int Queue::rear()
{
    if(isEmpty())
    {
        cout << "Queue is Empty." << endl;
        return INT_MIN;
    }
    return arr[Rear];
}

int main()
{
    Queue q1;
    q1.enqueue(3);
    q1.enqueue(7);
    q1.enqueue(2);
    q1.enqueue(5);
    q1.enqueue(9);
    q1.enqueue(3);
    cout << "Front of queue: " << q1.front() << endl;
    cout << "Rear of queue: " << q1.rear() << endl;
    cout << q1.dequeue() << " removed from queue." << endl;
    cout << "Front of queue: " << q1.front() << endl;
    cout << "Rear of queue: " << q1.rear() << endl;

    return 0;
}
/*
Expected output: Queue is full.
                 Front of queue: 3
                 Rear of queue: 9
                 3 removed from queue.
                 Front of queue: 7
                 Rear of queue: 9
*/