/* The program implements a function which inserts element into sorted order and another fuction that merges two
   linked list to return head of new list which has all the elements of two lists mergeed in sorted order.
*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void sorted_insert(Node** head,int data)
{
    Node* new_node = new Node();                      
    new_node->data = data;
    new_node->next = NULL;
    if((*head == NULL) || ((*head)->data > data))   //if head is NULL or its data is greater than new_node data
    {
        new_node->next = *head;                     //change head to new node
        *head = new_node; 
    }
    else
    {
        Node* temp_head = *head;
        while (temp_head->next != NULL)                   
        {
           if(temp_head->next->data > new_node->data)     //when data is smaller than data of head->next
           {
               new_node->next = temp_head->next;          //insert new node 
               temp_head->next = new_node;
               return;
           } 
           temp_head = temp_head->next;                   //else move to next node
        }
        temp_head->next = new_node;                       //if no node->data is smaller than new node data
    }                                                     //then add new node at list end
}

Node* merge_sorted(Node** head1,Node** head2)
{
    Node* temp_head1 = *head1;
    Node* temp_head2 = *head2;
    Node* final_head;
    if((temp_head1 == NULL) || (temp_head1->data > temp_head2->data))
    {
        final_head = temp_head2;             
        temp_head2 = temp_head2->next;
    }
    else
    {
        final_head = temp_head1;
        temp_head1 = temp_head1->next;
    }
    Node* end = final_head;                                //initialize temporaray end pointer pointing to final head
    while((temp_head1 != NULL) && (temp_head2 != NULL))
    {
        if(temp_head1->data < temp_head2->data)
        {
            end->next = temp_head1;                        
            temp_head1 = temp_head1->next;                  //move to next node in list 1 
            end = end->next;
        }
        else
        {
            end->next = temp_head2;
            temp_head2 = temp_head2->next;                  //move to next node in list 2
            end = end->next;
        }
    }
    if(temp_head1 == NULL)           //if head1 is NULL
    {
        end->next = temp_head2;      //add all remaining nodes of list 2
    }
    else
    {
        end->next = temp_head1;      //add all remaining nodes of list 1
    }
    return final_head;
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
    Node* head1 = NULL;
    sorted_insert(&head1,9);
    sorted_insert(&head1,3);
    sorted_insert(&head1,5);
    sorted_insert(&head1,10);
    cout << "1st Sorted list: ";
    print(head1);
    Node* head2 = NULL;
    sorted_insert(&head2,2);
    sorted_insert(&head2,5);
    sorted_insert(&head2,5);
    sorted_insert(&head2,6);
    cout << "2nd Sorted list: ";
    print(head2);
    Node* merged = merge_sorted(&head1,&head2);
    cout << "Merged list: ";
    print(merged);
}