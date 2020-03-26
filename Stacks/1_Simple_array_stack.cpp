/* Stacks are implemented through arrays or linked list by use of class or a struct. It is a data structure that follows
   First In Last Out (FILO) order for elements. Few basic functions are as follows:
   1. void push(...) : It pushes the element in the stack.
   2. int pop(...) : The function removes the topmost data from stack and gives the value of that data element
   3. int peek(...) : This function returns value of top most element
   4. bool isFull(...) : The function is used for knowing the status of stack, returns true if stack full.
   5. bool isEmpty(...) : The function returns true if stack is empty.
   **NOTE** : Stack implemented through arrays can only have fixed predefined capacity, whereas when implemented 
              linked list can have variable length. Variable length can also be acheived through dynamic allocation in array.
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

int main()
{
    Stack stack_1;
    for(int i = 0; i< 10; i++)
    {
        stack_1.push(i);
    }
    stack_1.push(10);
    cout << "Topmost element of stack: " << stack_1.peek() << endl;
    cout << "Poped element: " << stack_1.pop() << endl;
    cout << "Now, the topmost element is: " << stack_1.peek() << endl;

    return 0;
}
/*
Expected output: Stack overflow, no new elements can be pushed.
                 Topmost element of stack: 9
                 Poped element: 9
                 Now, the topmost element is: 8
*/
