/* For a given linked list, we need to check if a loop exists. If so then we define certain functions that find length
   loop, start point of loop and terminate the loop.
   example of a loop:  1->2->3  (Here next of last node points to previous element making a loop)
                          |  |
                          5<-4
    Loop Detection: Floyd's Algorithm is implemented. Two pointers, slow and fast, are used. If loop exists they will
                    point same node after few iterations.
    Length of loop: While implementating of Floyd's Algorithm, when slow and fast pointers point at same node, another
                    pointer pointing at that location is created and made to traverse the loop until reaches there again.
    Start of loop: The slow pointer moves 1 node for every 2 nodes moved by fast pointer. They meet after N iterations  
                   suct that slow moves N nodes and fast moves 2N nodes. Let
                   X : Number of nodes from head to start of loop.
                   Y : Number of nodes from start of loop to meet point.
                   C1 : Rotations by 'slow' in loop before meeting 'fast'.
                   C2 : Rotations by 'fast' in loop before meeting 'slow'.
                   L : Length of loop.
                   Therefore, N = X + Y + C1*L    and    2N = X + Y + C2*L
                   i.e. we get  (X + Y) = L(C2 - 2*C1)  which means distance from head to meet node is multiple of L.
                   Since meet node is already Y nodes ahead of start node, we conclude that distance from head to start
                   is same as distance to be traversed from meet to reach start again.
    Remove loop: By traversing (L-1) nodes from start, and making next = NULL, loop can be removed.      
*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int loop_length(Node *node)
{
    Node* temp_node = node;              // assign temporary pointer at meet node
    int length = 0;
    do
    {
        length++;
        temp_node =temp_node->next;
    } while (temp_node != node);        // traverse in loop until meet node is found again
    return length;
}

int detect_loop(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return loop_length(slow) ;
    } 
    return 0; 
}

int loop_start(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)                        // meet node reached
        {
            Node* temp_head = head;             // temp node from head starts  
            int start = 0;
            while (slow != temp_head)           // both move until they point same node
            {
                slow = slow->next;
                temp_head = temp_head->next;
                start++;
            }
            return start;
        }
    } 
}

void loop_terminate(Node* head,int size)
{
    Node* temp_head = head;
    for(int i = 0;i < size-1 ;i++)
        temp_head = temp_head->next;
    temp_head->next = NULL;
    cout << "Loop terminated." << endl;
}

int main()
{
    Node head, second, third, fourth, fifth;
    head.data = 1;
    head.next = &second;
    second.data = 2;
    second.next = &third;
    third.data = 3;
    third.next = &fourth;
    fourth.data = 4;
    fourth.next = &fifth;
    fifth.data = 5;
    fifth.next = &second;
    if(detect_loop(&head))
    {
        cout << "Loop is present. Length of loop : " << detect_loop(&head) << endl;;
        cout << "Loop starts at " << loop_start(&head) << " node (assuming head to be 0th node)" << endl;
        loop_terminate(&head,5);
    }
    else
        cout << "Loop is absent." << endl;
}
/*
Expected output:Loop is present. Length of loop : 4
                Loop starts at 1 node (assuming head to be 0th node)
                Loop terminated.
*/