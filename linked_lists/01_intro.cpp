/*Here Singly Linked List is implemented using a struct but can be done using a class also.
  The element of linked list is called a node. It consists of 2 basic blocks - the data of the node and address
  of next node. The last node of list has next = NULL.
  Here elements of list i.e. nodes can be also be declared as pointer of user defined nodes.
*/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void print(Node *point)
{
    while(point != NULL)
    {
        cout << point->data << "->";
        point = point->next;
    }
    cout << "NULL";
}

int main()
{
    Node head, second, third;
    head.data = 1;
    head.next = &second;

    second.data = 2;
    second.next = &third;

    third.data = 3;
    third.next = NULL;

    print(&head);
    cout << endl;
}