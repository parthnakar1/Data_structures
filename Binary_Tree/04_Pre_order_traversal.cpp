/* Pre Order Traversal is a Depth First Traversal. The order is :- <root><left><right>
   RECURSIVE Algorithm:
   ->Print current root data.
   ->Pass left child (if not NULL) to function.
   ->Pass right child (if not NULL) to function.
   ITERATIVE Algorithm:
   This algorithm uses a stack. STL library's <stack> header is used. The stack are of data type pointer to Node.
   ->If root is not NULL
      ->Push root into stack.
      ->while stk is not empty.
         ->Node* temp = stk.top()
         ->Print temp data.
         ->Pop top element of stk.
         ->Push left child (if not NULL) into stk
         ->Push right child (if not NULL) into stk.
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

void pre_order_rec(Node* root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        pre_order_rec(root->left);
        pre_order_rec(root->right);
    }
}

void pre_order_iter(Node* root)
{
    if (root != NULL)
    {
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty())
        {
            Node* temp = stk.top();
            cout << temp->data << " ";
            stk.pop();
            if(temp->right != NULL)
            {
                stk.push(temp->right);
            }
            if(temp->left != NULL)
            {
                stk.push(temp->left);
            }
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
    cout << "Pre Order Traversal(Recursive) : ";
    pre_order_rec(root);
    cout << endl;
    cout << "Pre Order Traversal(Iterative) : ";
    pre_order_iter(root);
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
Expected output: Pre Order Traversal(Recursive) : 1 2 4 8 5 3 6 9 10 7 
                 Pre Order Traversal(Iterative) : 1 2 4 8 5 3 6 9 10 7
*/