/* The elements of Queue are stored in a Stack. Whenever operations are to be performed, another temporary stack is
   used. The elements are enqueued by first copying into a temporary stack, new element is pushed and all elements
   are again transfered int original stack representing the queue.
*/
#include <iostream>
#include <limits.h>
# define Max 10
using namespace std;

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
};

void Stack::push(int data)
{
    if(top == (Max - 1))
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
    if(top < 0)
    {
        cout << "Stack is empty." << endl;
        return INT_MIN;
    }
    else
    {
        return arr[top--];
    }
}

void enqueue(Stack* q, int data)
{
    Stack s;
    while(q->top >= 0)
    {
        s.push(q->pop());
    }
    s.push(data);
    while (s.top >= 0)
    {
        q->push(s.pop());
    }
}

int dequeue(Stack* q)
{
    return q->pop();
}

int front(Stack* q)
{
    if(q->top >= 0)
    {
        return q->arr[q->top];
    }
    else
    {
        cout << "Queue is empty." << endl;
        return INT_MIN;
    }
}

int rear(Stack* q)
{
    if(q->top >= 0)
    {
        return q->arr[0];
    }
    else
    {
        cout << "Queue is empty." << endl;
        return INT_MIN;
    }
    
}

int main()
{
    Stack queue;
    enqueue(&queue, 3);
    enqueue(&queue, 8);
    enqueue(&queue, 7);
    cout << "Front: " << front(&queue) << endl;
    cout << "Rear: " << rear(&queue) << endl;
    cout << "Dequeued element: " << dequeue(&queue) << endl;
    cout << "Dequeued element: " << dequeue(&queue) << endl;
    cout << "Front: " << front(&queue) << endl;
    cout << "Rear: " << rear(&queue) << endl;
    cout << "Dequeued element: " << dequeue(&queue) << endl;
    cout << "Dequeued element: " << dequeue(&queue) << endl;

    return 0;
}
/*
Expected output: Front: 3
                 Rear: 7
                 Dequeued element: 3
                 Dequeued element: 8
                 Front: 7
                 Rear: 7
                 Dequeued element: 7
                 Stack is empty.
                 Dequeued element: -2147483648
NOTE: Here the element dequeued when queue is empty represents INT_MIN.
*/