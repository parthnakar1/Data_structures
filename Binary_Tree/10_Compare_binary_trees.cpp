/* Two Binary Trees are compared with respect to their structure and data.
   Binary Trees are SIMILAR when they have same structure and IDENTICAL when they have same structure as well as data.
   This is checked by checking each Node and its corresponding left and right children.
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

bool isSimilar(Node* root1, Node* root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if(root1 != NULL && root2 != NULL)
    {
        return (isSimilar(root1->left,root2->left) && isSimilar(root1->right,root2->right));
    }
    else
    {
        return false;
    }
}

bool isIdentical(Node* root1, Node* root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if ((root1 != NULL && root2 != NULL) && (root1->data ==root2->data))
    {
        return (isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right));
    }
    else
    {
        return false;
    }
    
}

int main()
{
    Node* root1 = NewNode(1);
    root1->left = NewNode(2);
    root1->right = NewNode(3);
    root1->left->right = NewNode(4);
    
    Node* root2 = NewNode(10);
    root2->left = NewNode(20);
    root2->right = NewNode(30);
    root2->left->right = NewNode(40);

    cout << "Are trees 1 and 2 Similar? = " << isSimilar(root1,root2) << endl;
    cout << "Are trees 1 and 2 Identical? = " << isIdentical(root1,root2) << endl;
    cout << "Is tree 1 identical to itself? = " << isIdentical(root1,root1) << endl;

    return 0;
}
/*  Binary Tree 1           Binary Tree 2
      1                        10
     / \                       / \
    /   \                     /   \
   2     3                   20   30
    \                         \
     4                        40
Expected output: Are trees 1 and 2 Similar? = 1
                 Are trees 1 and 2 Identical? = 0
                 Is tree 1 identical to itself? = 1
*/