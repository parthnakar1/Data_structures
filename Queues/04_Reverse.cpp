/* For reversing a queue,
   ->Dequeue all elements of queue and push them onto stack.
   ->Pop all elements of stack and enqueue them in a queue.
*/
#include <iostream>
#include <limits.h>
# define Max 10
using namespace std;
// Queue implementation
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
        Front = 0, Rear = 0;
    }
    else
    {
        Rear = (Rear + 1) % Max;
    }
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
        Rear = -1, Front = -1;
    }
    else
    {
        Front = (Front + 1) % Max;
    }
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
// Stack implementation
class Stack
{
    public:
    int top;
    int arr[Max];
    Stack()
    {
        top = -1;
    }
    void push(int data);
    int pop(void);
    int peek(void);
    bool isFull(void);
    bool isEmpty(void);
};

bool Stack::isEmpty()
{
    return (top < 0);
}

bool Stack::isFull()
{
    return (top == (Max - 1));
}

void Stack::push(int data)
{
    if(isFull())
    {
        cout << "Stack overflow, no new elements can be pushed." << endl;
    }
    else
    {
        arr[++top] = data;
    }
}

int Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stack is empty." << endl;
        return INT_MIN;
    }
    else
    {
        return arr[top--];
    }
}

int Stack::peek()
{
    if(isEmpty())
    {
        cout << "Stack is empty." << endl;
        return INT_MIN;
    }
    else
        return arr[top];
}

Queue reverse(Queue q)
{
    Stack s;
    while(!q.isEmpty())
    {
        s.push(q.front());
        q.dequeue();
    }
    while (!s.isEmpty())
    {
        q.enqueue(s.peek());
        s.pop();
    }
    return q;    
}

int main()
{
    Queue q1,q2;
    q1.enqueue(1);
    q1.enqueue(5);
    q1.enqueue(2);
    q1.enqueue(9);
    q1.enqueue(3);
    q1.enqueue(8);

    q2 = reverse(q1);
}
