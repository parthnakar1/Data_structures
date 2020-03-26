/* This technique of implementing stacks through dynamic array have advantage of no restriction of stack size.
   Each time the current array is full, a new array of double size will be created. This makes average time of a push 
   constant (however at times when array is full, they are copied into temporary array before moving to new array of
   double the size). */
#include <iostream>
#include <limits.h>
using namespace std;

class Stack
{
    private:
    int top, Size;
    void DoubleSize();
    public:
    int* current;
    Stack()
    {
        top = -1;
        Size = 1;
        current = new int[Size];
    }
    bool isEmpty();
    bool isFull();
    void push(int data);
    void pop();
    int peek();
};
bool Stack::isEmpty()
{
    return (top < 0);
}
bool Stack::isFull()
{
    return (top == (Size - 1));
}
void Stack::DoubleSize()
{
    int* temp = new int[Size];      //create temporary array of same size
    for(int i=0;i<Size;i++)
    {
        temp[i] = current[i];       //copy elements into temporary array
    }
    Size = Size*2;                  //double the size
    delete current;                 //delete current array to free up the space
    current = new int[Size];        //create new array of new doubled size
    for(int i=0;i<Size/2;i++)
    {
        current[i] = temp[i];       //copy elements from temporary array into new array 
    }
    delete temp;                    //delete temporary array and free up the space
}
void Stack::push(int data)
{
    if(isFull())
    {
        DoubleSize();
    }
    cout << data << " pushed to stack" << endl;
    current[++top] = data;
}
void Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        top--;
        cout << current[top] << " poped from stack" << endl;
    }
}
int Stack::peek()
{
    if(isEmpty())
    {
        cout << "Stack is empty" << endl;
        return INT_MIN;
    }
    else
    {
        return *current;
    }
}

int main()
{
    Stack stack_1;
    stack_1.push(4);
    cout << "Top: " << stack_1.peek() << endl;
    stack_1.push(6);
    stack_1.push(9);
    stack_1.pop();
    cout << "Top: " << stack_1.peek() << endl;

    return 0;
}
/*
Expected output: 4 pushed to stack
                 Top: 4
                 6 pushed to stack
                 9 pushed to stack
                 6 poped from stack
                 Top: 4
*/