/* Stacks can be used for checking whether parenthesis of an expression are balanced or not.
   The algorithm is as follows:
   ->Scan the expression from start.
   ->If character is opening braces i.e '(' or '{' or '[', push into the stack.
     Else If scanned character is closing braces i.e. ')' or '}' or ']',
      ->If top element of stack and scanned expression form a pair, pop an element from stack.
        Else push the scanned character.
    ->Repeat till end of expression, Parenthesis are balanced only if stack is empty.
*/
#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;
class Stack
{
    public:
    int top;
    char arr[10];
    Stack()
    {
        top = -1;
    }
    void push(char data);
    void pop(void);
    char peek(void);
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
void Stack::push(char data)
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
void Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        arr[top--];
    }
}
char Stack::peek()
{
    if(isEmpty())
    {
        return CHAR_MIN;
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


void check_balanced_parantheses(string s)
{
    Stack stack_1;
    char temp;
    for(int i=0;i<s.length();i++)
    {
        temp = s.at(i);
        if(temp == '(' || temp== '[' || temp== '{')
        {
            stack_1.push(temp);
            
        }
        else if(temp == '}' || temp== ']' || temp== ')')
        {
            if(temp == ']' && stack_1.peek() == '[')
            {
                stack_1.pop();    
            }
            else if(temp == '}' && stack_1.peek() == '{')
            {
                stack_1.pop();    
            }
            else if(temp == ')' && stack_1.peek() == '(')
            {
                stack_1.pop();    
            }
            else
            {
                stack_1.push(temp);
                break;
            }
        }
    }
    
    if(stack_1.isEmpty())
    {
        cout << "Parantheses are balanced." << endl;
    }
    else
    {
        cout << "Parantheses not balanced." << endl;
    }
}

int main()
{
    string s;
    cout << "Enter expression:";
    cin >> s;
    check_balanced_parantheses(s);

    return 0;
}

/*
Expected output: Enter expression:([]{[]()})
                 Parantheses are balanced.
*/
