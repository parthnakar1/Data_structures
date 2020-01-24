/*In this code insertion and deletion of nodes from random positions will be performed and length of list is found
    INSERTION:(at given position)- Reach to the node at (position-1), point next of new node to next of previous node
                                   and then change next of previous node to point at new node.
              (at mid position)- Two approches-> 1.Find length by traversing once and then go to (length/2) position to insert new node.
                                              -> 2.Hare Tortoise method: traverse using two pointers slow and fast such that for 1 traverse to
                                                   next node by slow, fast traverses 2 nodes.
    DELETION: Traverse through list to reach given (position-1), then temp node points next. Now change next at (position-1) to next of temp
              and delete temp.
    LENGTH of LIST: Traverse through the list once until NULL is encountered and and find numbers of nodes.
*/
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

int length_list(Node* head)
{
    int length = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

void insert(Node** head,int data,int position)
{
    Node* temp_head = *head;
    Node* new_node = new Node();
    new_node->data = data;
    int pos = 0;
    if(position > 0)         //Assumed head isn't asked to be changed.
    {
        while(pos < position-1)
        {
            temp_head = temp_head->next;
            pos++;
        }
        if(temp_head != NULL)
        {
            new_node->next = temp_head->next;
            temp_head->next = new_node;
        }
    }
}

void insert_mid(Node** head,int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    Node* slow = *head;
    Node* fast = (*head)->next;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    new_node->next = slow->next;
    slow->next = new_node;
}

void delete_random(Node** head,int position)
{
    Node* temp_head = *head;
    if(position == 0)
    {
        *head = temp_head->next;
        delete temp_head;
    }
    else
    {
        while(position-1 > 0)
        {
            temp_head = temp_head->next;
            position--;
        }
        if(temp_head->next != NULL)
        {
            Node* del = temp_head->next;
            temp_head->next = del->next;
            delete del;
        }
    }
    
}

void print(Node* head)
{
    Node* temp_head = head;                
    while(temp_head != NULL)               
    {
        cout << temp_head->data << "->";
        temp_head = temp_head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node* head = new Node();
    head->data = 0;
    head->next = NULL;
    insert(&head,1,1);
    insert(&head,3,2);
    insert(&head,4,3);
    cout << "Original list:";
    print(head);
    cout << "Length of original list:" << length_list(head) << endl;
    insert_mid(&head,2);
    cout << "After insertion at mid:";
    print(head);
    cout << "Length of new list:" << length_list(head) << endl;
    insert(&head,5,4);
    cout << "After random insertion:";
    print(head);
    cout << "Length of new list:" << length_list(head) << endl;
    delete_random(&head,3);
    cout << "After random deletion:";
    print(head);
    cout << "Length of new list:" << length_list(head) << endl;
}
/* Expected output:Original list:0->1->3->4->NULL
                   Length of original list:4
                   After insertion at mid:0->1->2->3->4->NULL
                   Length of new list:5
                   After random insertion:0->1->2->3->5->4->NULL
                   Length of new list:6
                   After random deletion:0->1->2->5->4->NULL
                   Length of new list:5
*/