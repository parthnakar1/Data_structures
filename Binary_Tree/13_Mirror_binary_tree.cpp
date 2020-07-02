/* The Mirror of a Binary Tree is achieved by swapping the pointers to left and right children.
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

void in_order(Node* root)
{
    if(root != NULL)
    {
        in_order(root->left);
        cout << root->data << " ";
        in_order(root->right);
    }
}

void mirror_rec(Node* root)
{
    if(root != NULL)
    {
        mirror_rec(root->left);
        mirror_rec(root->right);
        Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

void mirror_iter(Node* root)
{
    if(root != NULL)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            swap(temp->left,temp->right);
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

int main()
{
    Node* root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->right = NewNode(4);
    root->right->right = NewNode(5);
    cout << "In order before mirroring : ";
    in_order(root);
    cout << endl;
    mirror_rec(root);
    cout << "In order after mirroring (recursive) : ";
    in_order(root);
    cout << endl;
    mirror_iter(root);
    cout << "In order after mirroring twice (iterative) : ";
    in_order(root);
    cout << endl;

    return 0;
}
/* Binary Tree            Mirror
      1                      1
     / \                    / \
    /   \                  /   \
   2     3      <===>     3     2
    \     \              /     /
     4     5            5     4
Expected output: In order before mirroring : 2 4 1 3 5 
                 In order after mirroring (recursive) : 5 3 1 4 2 
                 In order after mirroring twice (iterative) : 2 4 1 3 5
*/