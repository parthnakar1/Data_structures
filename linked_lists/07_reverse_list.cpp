/* The linked list is reversed in O(n) time and O(1) extra space. 3 temporary pointers point to 3 nodes where 
next is changed to point the previous node and this is repeated for all nodes.*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
void add_to_list(Node** head,int data)
{
    Node* new_node = new Node();           
    new_node->data = data;                 
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
            temp_head =temp_head->next;
        }
        temp_head->next = new_node;        
    }
}

void reverse(Node** head)
{
    Node* prev = NULL;
    Node* temp = *head;             //temp pointer points to head 
    Node* temp_next = NULL;
    while(temp != NULL)
    {
        temp_next = temp->next;     //temp_next to next pointer
        temp->next = prev;          //next of emp is changed to its previous
        prev = temp;                //previous pointer now points to node pointed by temp
        temp = temp_next;           //temp now points to temp_next node (moves to next node of list)
    }
    *head = prev;                   //head of the list is changed
}

void partial_reverse(Node** head,int start_position)
{
    Node* temp_head = *head;
    while(temp_head != NULL && (start_position-1) > 0)
    {
        temp_head = temp_head->next;
        start_position--;
    }
    Node* prev = temp_head->next;
    Node* temp = NULL;
    if(prev->next != NULL)
    {
        temp = prev->next;
        prev->next = NULL;
    }
    Node* temp_next = NULL;
    while(temp != NULL)
    {
        temp_next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = temp_next;
    }
    temp_head->next = prev;
}

void print(Node* head)
{
    while(head != NULL)
    {
        cout << head->data <<"->";
        head = head->next;
    }
    cout <<"NULL" << endl;
}

int main()
{
    Node* head = NULL;
    add_to_list(&head,0);
    add_to_list(&head,1);
    add_to_list(&head,2);
    add_to_list(&head,3);
    add_to_list(&head,4);
    add_to_list(&head,5);    
    add_to_list(&head,6);
    add_to_list(&head,7);
    cout << "Original list: ";
    print(head);
    reverse(&head);
    cout << "Reversed list: ";
    print(head);
    reverse(&head);
    cout << "Original list again: ";
    print(head);
    cout << "Partially reversed list: ";
    partial_reverse(&head,4);
    print(head);

    return 0;
}
/*Expected output: Original list: 0->1->2->NULL
                   Reversed list: 2->1->0->NULL
*/