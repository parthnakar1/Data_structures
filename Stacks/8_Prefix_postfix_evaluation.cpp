/* Infix Evaluation:
    ->Scan characters from end of the expression.
    ->If character is operand, push into stack.
      Else pop operand1, pop operand2 from stack, perform <operand1> operator <operand2>. Push the result into stack.
    ->Repeat till expression ends and the final value stored in stack is result.
   Postfix Evaluation:
    ->->Scan characters from start of the expression.
    ->If character is operand, push into stack.
      Else pop operand1, pop operand2 from stack, perform <operand2> operator <operand1>. Push the result into stack.
    ->Repeat till expression ends and the final value stored in stack is result.
NOTE: For expressions including BRACKETS, operations inside should be evaluated first.
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

int Prefix_evaluation(string exp)
{
    int op1,op2;
    Stack stk;
    for(int i = exp.length()-1; i >= 0; i--)
    {
        if(exp[i] > 47)
        {
            stk.push(int(exp[i]) - 48);
        }
        else
        {
            op1 = stk.peek();
            stk.pop();
            op2 = stk.peek();
            stk.pop();
            switch (exp[i])
            {
            case '/': stk.push(op1/op2);
                break;
            case '*': stk.push(op1*op2);
                break;
            case '+': stk.push(op1+op2);
                break;
            case '-': stk.push(op1-op2);
                break;
            default:
                break;
            }
        }
    }
    return stk.peek();
}

int Postfix_evaluation(string exp)
{
    Stack stk;
    int op1,op2;
    for(int i = 0; i < exp.length(); i++)
    {
        if(exp[i] > 47)
        {
            stk.push(int(exp[i]) - 48);
        }
        else
        {
            op2 = stk.peek();
            stk.pop();
            op1 = stk.peek();
            stk.pop();
            switch (exp[i])
            {
            case '/': stk.push(op1/op2);
                break;
            case '*': stk.push(op1*op2);
                break;
            case '+': stk.push(op1+op2);
                break;
            case '-': stk.push(op1-op2);
                break;
            default:
                break;
            }
        }
    }
    return stk.peek();
}

int main()
{
    string prefix = "-+/42*561";
    string postfix = "42/56*+1-";
    cout << "Prefix Evaluation: " << prefix << " = " << Prefix_evaluation(prefix) << endl;
    cout << "Postfix Evaluation: " << postfix << " = " << Postfix_evaluation(postfix) << endl;

    return 0;
}

/*
Expected output: Prefix Evaluation: -+/42*561 = 31
                 Postfix Evaluation: 42/56*+1- = 31
*/