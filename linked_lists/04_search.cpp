/*The code includes functions for linear search and value of data at a given position.
  1. int search(...) - traverses through list until the data element is found and returns its position.
  2. int value_at_position(...) - returns value at postion passed as parameter.
*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int search(Node* head,int x)
{
    Node* temp_head = head;
    int count = 0;
    while(temp_head != NULL)                    // traverse until reaches the end of list
    {
        if(temp_head->data == x)
            return count;
        count++;
        temp_head = temp_head->next;
    }
    return -1;
}

int value_at_position(Node* head,int position)
{
    Node* temp_head = head;
    while(temp_head != NULL)
    {
        if(position == 0)
        {
            return temp_head->data;
        }
        temp_head = temp_head->next;
        position--;
    }
    return -1;
    

}

int main()
{
    Node head, second, third, fourth;
    head.data = 4;
    head.next = &second;
    second.data = 3;
    second.next = &third;
    third.data = 6;
    third.next = &fourth;
    fourth.data = 1;
    fourth.next = NULL;
    int position = 2;
    cout << "1 is at " << search(&head,1) << endl;
    cout << "Value at position " << position << ":" << value_at_position(&head,position) << endl;
    return 0;
}
// Expected output:1 is at 3
//                 Value at position 2:6