/*The program uses iterative approach to count occurences of given data element in the entire lists.
*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
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

int frequency(Node* head,int data)
{
    Node* temp_head = head;
    int freq = 0;
    while(temp_head != NULL)
    {
        if(temp_head->data == data)
            freq++;
        temp_head = temp_head->next;
    }
    return freq;
}

int main()
{
    Node *head = NULL;
    add_to_list(&head,0);
    add_to_list(&head,1);
    add_to_list(&head,2);
    add_to_list(&head,1);
    add_to_list(&head,5);
    cout << "Frequency of 1:" << frequency(head,1) << endl;
}
/*Expected output: Frequency of 1:2 */