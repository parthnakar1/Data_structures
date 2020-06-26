/* Level Order Traversal is Breadth First Traversal. In this traversal, we move from lowest level(root) to leaves step by
   step left to right in a given level.
   Algorithm:
   This algorithm uses a queue. The STL library's <queue> header is used. The queue is of data type pointer to Node.
   ->If root != NULL
      ->Push root into the queue q.
      ->While q is not empty
         ->Node* temp = q.front()
         ->Print data of temp.
         ->Push left child (if not NULL) into q.
         ->Push right child (if not NULL) into q.
         ->Pop front element of q.
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
            if(temp->right != NULL)
            {
                q.push(temp->right);
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
    cout << "Level Order Traversal : ";
    level_order(root);
    cout << endl;

    return 0;
}
/*  Binary Tree        Depth
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
Expected output: Level Order Traversal : 1 2 3 4 5 6 7 8 9 10
*/