/* A Node is to be deleted from a Binary Tree by passing its data value as key to shrink the tree. The deepest and
   rightmost Node is placed at the position of the Node to be deleted. This is done in order to maintain the balance
   of the tree.
   Algorithm:
   ->Find the Node to be deleted and last Node.
   ->Change the data of Node to be deleted as of last Node's data.
   ->Traverse till the parent of the last Node's parent, change its pointer to left child at NULL and delete the last Node.
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

void delete_node(Node* root,int key)
{
    if(root != NULL)
    {
        queue<Node*> q;
        q.push(root);
        Node* to_del = NULL;
        Node* last = NULL;
        while (!q.empty())
        {
            Node* temp = q.front();
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
            if(temp->data == key)
            {
                to_del = temp;
            }
            if(q.size() == 1)
            {
                last = temp;
            }
            q.pop();
        }
        to_del->data = last->data;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left != NULL)
            {
                if(temp->left == last)
                {
                    temp->left = NULL;
                    delete(last);
                    break;
                }
                else
                {
                    q.push(temp->left);
                }
            }
            if(temp->right != NULL)
            {
                if(temp->right == last)
                {
                    temp->right = NULL;
                    delete(last);
                    break;
                }
                else
                {
                    q.push(temp->right);
                }
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
    cout << "Level Order Traversal before deleting Node: ";
    level_order(root);
    cout << endl;
    delete_node(root,5);
    cout << "Level Order Traversal after deleting Node: ";
    level_order(root);
    cout << endl;

    return 0;
}
/* Original Tree before deleting a Node,
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
Expected output: Level Order Traversal before deleting Node: 1 2 3 4 5 6 7 8 9 10 
                 Level Order Traversal after deleting Node: 1 2 3 4 10 6 7 8 9 
  Modified Tree after deleting a Node,
    Binary Tree        Depth
        1               -1
       / \
      /   \
     /     \
    2       3           -2
   / \     / \
  /   \   /   \
 4    10 6     7        -3
  \       \
   8       9            -4
*/