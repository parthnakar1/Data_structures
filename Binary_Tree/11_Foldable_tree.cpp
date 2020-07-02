/* A Binary Tree is Foldable if its left and right subtrees are structure wise its mirror image of each other. A NULL
   tree as well as tree with Single root (no children) are Foldable.
   The left and right children of subtrees are compared interchangeably.
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

bool isStructureSame(Node* root1, Node* root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if(root1 != NULL && root2 != NULL)
    {
        return (isStructureSame(root1->left,root2->right) && isStructureSame(root1->right,root2->left));
    }
    else
    {
        return false;
    }
}

bool isFoldable(Node* root)
{
    if(root == NULL)
    {
        return true;
    }
    else
    {
        return isStructureSame(root->left,root->right);
    }
}

int main()
{
    Node* root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->right = NewNode(4);
    root->right->left = NewNode(5);

    cout << "Is tree foldable? " << isFoldable(root) << endl;

    return 0;
}
/* Binary Tree
    1
   / \
  /   \
 2     3
  \   /
   4 5
Expected output: Is tree foldable? 1
*/