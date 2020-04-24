/* Queue is implemented uses Linked List. The advantage of this type of implementation is that it has no constraint on
   length. The Queue is accessed using two pointers :- *head and *tail. Other operations remain same.
*/
#include <iostream>
#include <limits.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void enqueue(Node** head, Node** tail, int data)
{
    Node* new_node = new Node();
    new_node->data = data;                     // Assign data to new node.
    new_node->next = NULL;
    if(*head == NULL && *tail == NULL)
    {
        *head = new_node;                      // If the queue is initially empty, both head and tail
        *tail = new_node;                      // points to same node.
        return;
    }
    (*tail)->next = new_node;                  // Link new node in queue.
    *tail = new_node;                          // Change the tail to new node.
}

void dequeue(Node** head, Node** tail)
{
    if(*head == NULL && *tail == NULL)
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        Node* temp = *head;
        if((*head)->next == NULL)              // When queue has single element, after execution of
        {                                      // dequeue function tail should point to NULL.
            *tail = NULL;
        }
        *head = (*head)->next;
        delete temp;
    }
}

int front(Node* head)
{
    if(head == NULL)
    {
        cout << "Queue is Empty." << endl;
        return INT_MIN;
    }
    return head->data;
}

int rear(Node* tail)
{
    if(tail == NULL)
    {
        cout << "Queue is Empty." << endl;
        return INT_MIN;
    }
    return tail->data;
}

int main()
{
    Node *head = NULL, *tail = NULL;
    enqueue(&head, &tail, 4);
    enqueue(&head, &tail, 7);
    cout << "Rear: " << rear(tail) << endl;
    cout << "Front: "<< front(head) << endl;
    dequeue(&head,&tail);
    enqueue(&head,&tail,6);
    dequeue(&head,&tail);
    cout << "Rear: " << rear(tail) << endl;
    cout << "Front: " << front(head) << endl;
    dequeue(&head,&tail);
    dequeue(&head,&tail);

    return 0; 
}
/*
Expected output: Rear: 7
                 Front: 4
                 Rear: 6
                 Front: 6
                 Queue is empty.
*/