/* Sorting a Queue by ITERATIVE approach can be done by following steps:
   The logic is to find the smallest number in the queue, note its index and put it at end of Queue.
   ->Enqueue and Dequeue each element of the Queue and find the index of minimum.
   ->Enqueue and Dequeue each element of the Queue except the index of minimum. Enqueue that value at end of the Queue.
   ->Repeat the same process again but not considering the minimum found i.e. the length of finding the minimum decreases 
     with each iteration.
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

void sort(Queue &q)
{
    int i,j,k,current,min_index,min = INT_MAX;
    for(i = 0; i < Max; i++)
    {
        for(j = 0; j < Max; j++)
        {
            current = q.front();
            q.dequeue();
            if(min > current && j < Max-i)    // Find the minimum, and by j < Max-i we ensure no same vale is selected
            {                                 // as minimum again. This helps in finding 1st, 2nd, ... minimums.
                min = current;
                min_index = j;
            }
            q.enqueue(current);
        }
        for(k = 0; k < Max; k++)
        {
            current = q.front();
            q.dequeue();
            if(k != min_index)
            {
                q.enqueue(current);
            }
        }
        q.enqueue(min);
        min = INT_MAX;
    }
}
int main()
{
    Queue q1;
    q1.enqueue(6);
    q1.enqueue(3);
    q1.enqueue(8);
    q1.enqueue(1);
    q1.enqueue(5);
    cout << "Original Queue : ";
    for(int i = 0;i < Max;i++)
    {
        cout << q1.arr[i] << " ";
    }
    sort(q1);
    cout << endl << "Sorted Queue : ";
    for(int i = 0;i < Max;i++)
    {
        cout << q1.arr[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
Expected output: Original Queue : 6 3 8 1 5 
                 Sorted Queue : 1 3 5 6 8
*/