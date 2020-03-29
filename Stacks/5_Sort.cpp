/* The below code sorts a stack by ITERATIVE approach.
   The logic for following code is somewhat parallel to bubble sort, however the difference is that only top element
   of the stack can be accessed at a time.
   Create an empty stack.
        ->Pop an top element (temp) from original stack
            ->Pop elements from new stack into original until elements are greater than temp
        ->push temp into new stack
   return new stack
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
        return arr[--top];
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

Stack sort(Stack stack_1)
{
    int temp;
    Stack sort_stack;                       // new stack
    while(!stack_1.isEmpty())               // loop till all elements are transfered to new stack in sorted order
    {
        temp = stack_1.peek();              //peek temp from original stack
        stack_1.pop();                      //pop it
        while((sort_stack.peek() > temp) && (!sort_stack.isEmpty())) 
        {
            stack_1.push(sort_stack.peek());   // push top element of new stack into original stack if smaller than temp
            sort_stack.pop();
        }
        sort_stack.push(temp);               //push temp in new stack
        cout << "temp: " << temp << endl;
        cout << "orignal ";
        print_stack(stack_1);
        cout << "new ";
        print_stack(sort_stack);
        cout << endl;
    }
    return sort_stack;
}

int main()
{
    Stack stack_1;
    stack_1.push(4);
    stack_1.push(8);
    stack_1.push(6);
    stack_1.push(7);
    cout << "Original ";
    print_stack(stack_1);
    Stack sorted = sort(stack_1);
    cout << "Sorted ";
    print_stack(sorted);

    return 0;
}
/*
Expected output: Original stack: Stack: 4-8-6-7-
                 Sorted stack: Stack: 4-6-7-8-

Iterative explanation:
new Stack is empty.
temp: 7
orignal Stack: 4-8-6-
new Stack: 7-

temp: 6
orignal Stack: 4-8-7-
new Stack: 6-

temp: 7
orignal Stack: 4-8-
new Stack: 6-7-

temp: 8
orignal Stack: 4-
new Stack: 6-7-8-

temp: 4
orignal Stack: 8-7-6-
new Stack: 4-

temp: 6
orignal Stack: 8-7-
new Stack: 4-6-

temp: 7
orignal Stack: 8-
new Stack: 4-6-7-

temp: 8
orignal Stack: 
new Stack: 4-6-7-8-
*/