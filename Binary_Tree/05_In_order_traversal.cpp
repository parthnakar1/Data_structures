/* In Order Traversal is a Depth First Traversal. The order is :- <left><root><right>
   RECURSIVE Algorithm:
   ->Pass left child (if not NULL) to function.
   ->Print current root data.
   ->Pass right child (if not NULL) to function.
   ITERATIVE Algorithm:
   This algorithm uses a stack. STL library's <stack> header is used. The stack are of data type pointer to Node.
   ->Node* temp = root
   ->while(1)
      ->If temp is not NULL
         ->Push temp into stk.
         ->temp point to left child.
      ->Else
         ->Break the loop if stk is Empty.
         ->Print data of top node data.
         ->temp points to right child of top element of stk.
         ->Pop top element of stk.
*/
#include<iostream>
#include<stack>
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

void in_order_rec(Node* root)
{
    if(root != NULL)
    {
        in_order_rec(root->left);
        cout << root->data << " ";
        in_order_rec(root->right);
    }
}

void in_order_iter(Node* root)
{
    stack<Node*> stk;
    Node* temp = root;
    while(1)
    {
        if(temp != NULL)
        {
            stk.push(temp);
            temp = temp->left;
        }
        else
        {
            if(stk.empty())
            {
                break;
            }
            cout << stk.top()->data << " ";
            temp = stk.top()->right;
            stk.pop();
        }
    }
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
    root->left->left->right = NewNode(8);
    root->right->left->right = NewNode(9);
    root->right->left->right->left = NewNode(10);
    cout << "In Order Traversal(Recursive) : ";
    in_order_rec(root);
    cout << endl;
    cout << "In Order Traversal(Iterative) : ";
    in_order_iter(root);
    cout << endl;

    return 0;
}
/*  Binary Tree
        1
       / \
      /   \
     /     \
    2       3
   / \     / \
  /   \   /   \
 4     5 6    7
  \       \
   8       9
           /
          10
Expected output: In Order Traversal(Recursive) : 4 8 2 5 1 6 10 9 3 7 
                 In Order Traversal(Iterative) : 4 8 2 5 1 6 10 9 3 7 
*/
