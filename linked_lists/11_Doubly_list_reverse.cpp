/* Most of the operations on Doubly linked list are similar as in Singly linked list.
   However few operations have few changes. They are discussed here.
   void reverse(...) : It reverses the doubly linked list.
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
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void reverse(Node **head)
{
    Node* temp_head = *head;
    Node* successive = NULL;
    while(temp_head != NULL)
    {
        successive = temp_head->previous;
        temp_head->previous = temp_head->next;
        temp_head->next = successive;
        temp_head = temp_head->previous;
    }
    *head = successive->previous;
}

int main()
{
    Node *head = NULL;
    add_node(&head,5);
    add_node(&head,1);
    add_node(&head,9);
    add_node(&head,2);
    add_node(&head,3);
    cout << "Original list: ";
    print(head);
    reverse(&head);
    cout << "Reversed list: ";
    print(head);

    return 0;
}
/* Expected output: Original list: 5->1->9->2->NULL
                    Reversed list: 2->9->1->5->NULL
*/