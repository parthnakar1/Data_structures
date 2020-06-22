/* Implementation of Binary trees using Nodes is the most general form. It is known as linked / dynamic representation
   representation owing to use of Nodes that can be added dynamically. The Node as a basic unit consist of data member
   and pointer to its left and right child.
*/
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* NewNode(int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int main()
{
    Node* root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
    root->left->right = NewNode(5);
    root->right->left = NewNode(6);
    root->right->right = NewNode(7);

    return 0;
}
/* Binary Tree
     1
    / \
   /   \
  2     3
 / \   / \
4   5 6   7
*/