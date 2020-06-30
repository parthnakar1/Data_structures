/* A Node is inserted in Binary Tree using level order traversal. New Node is inserted at a position where left child or
   right child is NULL whichever is encountered first. Level Order Traversal for inserting Node benefits in balancing the
   tree.
*/
#include<iostream>
#include<queue>
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

void level_order(Node* root)
{
    if(root != NULL)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            cout << temp->data << " ";
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            q.pop();
        }
    }
}

void insert_node(Node* root,int data)
{
    if(root == NULL)
    {
        root = NewNode(data);
    }
    else
    {
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            Node* temp = q.front();
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            else
            {
                temp->left = NewNode(data);
                break;
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            else
            {
                temp->right = NewNode(data);
                break;
            }
            q.pop();
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
    cout << "Level Order Traversal before inserting Node: ";
    level_order(root);
    cout << endl;
    insert_node(root,11);
    cout << "Level Order Traversal after inserting Node: ";
    level_order(root);
    cout << endl;

    return 0;
}
/* Original Tree before inserting a Node,
    Binary Tree        Depth
        1               -1
       / \
      /   \
     /     \
    2       3           -2
   / \     / \
  /   \   /   \
 4     5 6    7         -3
  \       \
   8       9            -4
           /
          10            -5
Expected output: Level Order Traversal before inserting Node : 1 2 3 4 5 6 7 8 9 10 
                 Level Order Traversal after inserting Node : 1 2 3 4 5 6 7 11 8 9 10
  Modified Tree after inserting a Node,
      Binary Tree        Depth
          1               -1
         / \
        /   \
       /     \
      2       3           -2
     / \     / \
    /   \   /   \
   4     5 6    7         -3
  / \       \
 11  8       9            -4
            /
           10             -5
*/