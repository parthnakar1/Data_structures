/*  This is a code that explains Singly Linked List and few basic operations needed to form the list.
    New nodes are usually added to Singly Linked List at the end and the list keeps on growing.
    The three methods/functions implemented here are
    1. void add_to_list(...) - adds new node to the list at the end by finding last node pointing to NULL
    2. void print(...) - traverses through the list and prints every data member
    3. void delete_list(...) - deletes all members of the list
*/
#include <iostream>
using namespace std;

struct Node
{
    int data;        //data of node
    Node* next;      //pointer to next node to keep the list linked.
};

void add_to_list(Node** head,int data)
{
    Node* new_node = new Node();           //create new node 
    new_node->data = data;                 //assign the data
    new_node->next = NULL;                 //next points to NULL since added last
    if(*head == NULL)                      //if head itself is null
    {
        *head = new_node;                  //make new node as head
    }
    else
    {
        Node* temp_head = *head;           //make temp node pointing to head
        while(temp_head->next != NULL)     //find last node 
        {
            temp_head =temp_head->next;
        }
        temp_head->next = new_node;        //next of last node points to new node
    }
}

void delete_list(Node** head)
{
    Node* current = *head;                //current node points to head
    Node* next_node;                      // next node keeps track of when list terminates
    while(next_node != NULL)              
    {
        next_node = current->next;       
        delete current;
        current = next_node;
    }
    *head = NULL;
}

void print(Node* head)
{
    Node* temp_head = head;                //make temp node pointing to head
    while(temp_head != NULL)               //print data of every node and stop at last
    {
        cout << temp_head->data << "->";
        temp_head = temp_head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node* head = NULL;
    add_to_list(&head,0);
    add_to_list(&head,1);
    add_to_list(&head,2);
    add_to_list(&head,3);
    print(head);
    delete_list(&head);
    print(head);
}
/* Expected output: 0->1->2->3->NULL
                    NULL
*/