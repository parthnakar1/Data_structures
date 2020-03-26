/* Stacks are implemented using linked list. The benefit of this implementation is that a stack of variable length can
   be created. The methods of this implementation remain same.
*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void push(Node** current,int data)
{
    Node* new_node = new Node();                    //create new node to push in the stack
    new_node->data = data;                          //assign data
    new_node->next = *current;                      //point next of new node to previous current node
    *current = new_node;                            //change current of the stack
    cout << data << " pushed to stack" << endl;
}

int peek(Node* current)
{
    if(current != NULL)
    {
        return current->data;
    }
    else
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    
}

void pop(Node** current)
{
    if(*current != NULL)
    {
        Node* temp = *current;                              
        *current = (*current)->next;
        cout << temp->data << " poped from stack" << endl;
        delete temp;
    }
    else
    {
        cout << "Stack is already empty" << endl;
    }
}

int main()
{
    Node* current = NULL;
    push(&current,1);
    cout << "Top element: " << peek(current) << endl;
    push(&current,4);
    push(&current,6);
    pop(&current);
    cout << "Top element: " << peek(current) << endl;

    return 0;
}
/*
Expected output: 1 pushed to stack
                 Top element: 1
                 4 pushed to stack
                 6 pushed to stack
                 6 poped from stack
                 Top element: 4
*/