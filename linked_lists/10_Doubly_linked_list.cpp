/* Unlike Singly linked lists, Doubly linked lists have two pointers which point at previous and next node.
   It can be traversed in forward as well as backward direction.
   The previous of 1st node points at Null and next of last node too points at Null.
*/
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* previous;
    Node* next;
};

void add_node(Node **head,int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->previous = NULL;
    new_node->next = NULL;
    if(*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node* temp_head = *head;
        while(temp_head->next != NULL)
        {
            temp_head = temp_head->next;
        }
        temp_head->next = new_node;
        new_node->previous = temp_head;
    }
}

void print(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << "<->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;
    add_node(&head,5);
    add_node(&head,1);
    add_node(&head,9);
    add_node(&head,2);
    cout << "Doubly linked list: ";
    print(head);

    return 0;
}
/* Expected output: Doubly linked list: 5->1->9->2->NULL */