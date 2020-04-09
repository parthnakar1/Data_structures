/*  Infix, Postfix and Prefix notations are three different but equivalent ways of writing expressions.
    Infix Notation: Operators are written in-between their operands. Eg.: a/b+c*d-e
    Prefix Notation: Operators are written before their operands. Eg.: -+/ab*cde
    Postfix Notation: Operators are written after their operands. Eg.: ab/cd*e-+
    All the above three ways follow same rule of precedence/priority (BODMAS). However Infix is more human readable while 
    Prefix and Postfix are more machine readable.
    Infix to Postfix:
     ->Scan single character of infix expression from left to right.
     ->If scanned character is operand, add it to postfix expression.
       Else,->If priority of scanned operator is greater than top of stack, push operator.
              Else pop all operators of stack with lower priority, append to postfix and push current operator.
     ->Repeat above steps till end.
    Infix to Prefix:
     ->Reverse the Infix expression.
     ->Convert reversed expression to the Postfix form.
     ->Reverse this expression again to obtain Prefix form.
*/
#include <bits/stdc++.h>
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
        cout << "Stack is empty" << endl;
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
        return INT_MIN;
    }
    else
        return arr[top];
}
//Function for assigning priority.
int Priority(char c1)
{
    if (c1 == '^') return 5;
    else if(c1 == '/') return 4;
    else if(c1 == '*') return 3;
    else if(c1 == '+') return 2;
    else return 1;
}

string infix_to_postfix(string exp)
{
    Stack stk;
    string postfix = "";
    for(int i = 0; i < exp.length(); i++)
    {
        if(exp[i] > 47)
        {
            postfix += exp[i];
        }
        else
        {
            if(Priority(exp[i]) >= Priority(char(stk.peek())))
            {
                stk.push(int(exp[i]));
            }
            else
            {
                while(!(stk.isEmpty()) && (Priority(exp[i]) <= Priority(char(stk.peek()))))
                {
                    postfix += char(stk.peek());
                    stk.pop();
                }
                stk.push(int(exp[i]));
            }
        }
    }
    while(!(stk.isEmpty()))
    {
        postfix += char(stk.peek());
        stk.pop();
    }
    return postfix;
}

string infix_to_prefix(string exp)
{
    reverse(exp.begin(),exp.end());
    string pre = infix_to_postfix(exp);
    reverse(pre.begin(),pre.end());
    return pre;
}

int main()
{
    string expression = "4/2+5*6-1";
    string postfix = infix_to_postfix(expression);
    string prefix = infix_to_prefix(expression);
    cout << "Infix: " << expression << endl << "Postfix: " << postfix << endl << "Prefix: " << prefix << endl;

    return 0;
}

/*
Expected output: Infix: 4/2+5*6-1
                 Postfix: 42/56*+1-
                 Prefix: -+/42*561
*/