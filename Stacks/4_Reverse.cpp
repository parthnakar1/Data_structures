#include <iostream>
#include <limits.h>
using namespace std;
class Stack
{
    public:
    int top;
    int arr[10];
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
    return (top == 9);
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

void print_stack(Stack s)
{
    cout << "Stack: ";
    for(int i=0;i<=s.top;i++)
    {
        cout << s.arr[i] << "-";
    }
    cout << endl;
}

Stack reverse(Stack s)
{
    Stack n;
    int m = s.top;
    for(int i=0;i<=m;i++)
    {
        n.push(s.peek());
        s.pop();
    }
    
    return n;
}

int  main()
{
    Stack stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    print_stack(stack1);
    Stack stack2 = reverse(stack1);
    print_stack(stack2);

    return 0;
}
/*
Expected output: Stack: 1-2-3-4-
                 Stack: 4-3-2-1-
*/