/* Sometimes two linked lists with different head pointers may merge into single list. In this program we aim to find 
   the merge point (also known as Y-intersection point).
   Let l1 and l2 be the length of the two linked lists as measured from their heads respectively. Let the two lists
   have n nodes in common. The differnce between l1 and l2 be d.
   Move d nodes in longer list and then by moving 1 node at time in both the list, they will meet at the coomon merge
   point.
   LIST 1 :  0->3->6->8->NULL  
   LIST 2 :      5¬^
*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int list_length(Node* head)
{
    Node* temp_head = head;
    int length = 0;
    while (temp_head != NULL)
    {
        length++;
        temp_head = temp_head->next;
    }
    return length;
}

Node* merge_point(Node* head1,Node* head2)
{
    Node* temp_head1 = head1;
    Node* temp_head2 = head2;
    int length1, length2, diff;
    length1 = list_length(temp_head1);
    length2 = list_length(temp_head2);
    if(length1 >= length2)
    {
        diff = length1 - length2;
        for(int i=0;i<diff;i++)
        {
            temp_head1 = temp_head1->next;    //move d nodes in longer list
        }
    }
    else
    {
        diff = length2 - length1;
        for(int i=0;i<diff;i++)
        {
            temp_head2 = temp_head2->next;    //move d nodes in longer list
        }
    }
    while(temp_head1 != temp_head2 && temp_head1 != NULL && temp_head2 != NULL)
    {
        temp_head1 = temp_head1->next;
        temp_head2 = temp_head2->next;
    }
    return temp_head2;
}

int main()
{
    Node head1,head2,second1,second,third;
    head1.data = 0;
    head1.next = &second1;
    head2.data = 5;
    head2.next = &second;
    second1.data = 3;
    second1.next = &second;
    second.data = 6;
    second.next = &third;
    third.data = 8;
    third.next = NULL;
    Node* merge = merge_point(&head1,&head2);
    cout << "Merge Node data: " << merge->data << endl;

    return 0;
}
