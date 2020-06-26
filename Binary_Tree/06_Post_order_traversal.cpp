/* The Post Order Traversal is a Depth First Traversal. The order is :- <left><right><root>
   RECURSIVE Algorithm:
   ->Pass left child (if not NULL) to function.
   ->Pass right child (if not NULL) to function.
   ->Print current root data.
   ITERATIVE Algorithm:
   This algorithm uses two stacks. STL library's <stack> header is used. The stacks are of data type pointer to Node.
   ->Push root into stk.
   ->while stk is not empty.
      ->Node* temp = stk.top
      ->Pop  top element of stk.
      ->Push temp into res.
      ->Push temp's left child (if not NULL) into stk.
      ->Push temp's right child (if not NULL) into stk.
      (Repeat the steps.)
    ->Pop all the elements of res one by one and print them.
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

void post_order_rec(Node* root)
{
    if(root != NULL)
    {
        post_order_rec(root->left);
        post_order_rec(root->right);
        cout <<  root->data << " ";
    }
}

void post_order_iter(Node* root)
{
    stack<Node*> stk, res;
    stk.push(root);
    while(!stk.empty())
    {
        Node* temp = stk.top();
        stk.pop();
        res.push(temp);
        if(temp->left != NULL)
        {
            stk.push(temp->left);
        }
        if(temp->right != NULL)
        {
            stk.push(temp->right);
        }
    }
    while(!res.empty())
    {
        cout << res.top()->data << " ";
        res.pop();
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
    cout << "Post Order Traversal(Recursive) : ";
    post_order_rec(root);
    cout << endl;
    cout << "Post Order Traversal(Iterative) : ";
    post_order_iter(root);
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
Expected output: Post Order Traversal(Recursive) : 8 4 5 2 10 9 6 7 3 1 
                 Post Order Traversal(Iterative) : 8 4 5 2 10 9 6 7 3 1
*/