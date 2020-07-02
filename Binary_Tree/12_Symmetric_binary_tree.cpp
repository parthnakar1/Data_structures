/* To check whether a Binary Tree symmetric or not, we compare the left and right subtrees of the root. They should be
   mirror image of each other for the tree to be symmetric. This can be done recursively as well as iteratively.
   The left child is compared with right child and vice-versa.
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

bool util(Node* left_node, Node* right_node)
{
    if(left_node == NULL && right_node == NULL)
    {
        return true;
    }
    else if ((left_node != NULL && right_node != NULL) && (left_node->data == right_node->data))
    {
        return (util(left_node->right,right_node->left) && util(left_node->left,right_node->right));
    }
    else
    {
        return false;
    }
    
}

bool isSymmetricRec(Node* root)
{
    return util(root,root);
}

bool isSymmetricIter(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(root);
    Node *left_node, *right_node;
    while (!q.empty())
    {
        left_node = q.front();
        q.pop();
        right_node = q.front();
        q.pop();
        if(left_node->data != right_node->data)
        {
            return false;
        }

        if(left_node->left != NULL && right_node->right != NULL)
        {
            q.push(left_node->left);
            q.push(right_node->right);
        }
        else if(left_node->left != NULL || right_node->right != NULL)
        {
            return false;
        }
        
        if(left_node->right != NULL && right_node->left != NULL)
        {
            q.push(left_node->right);
            q.push(right_node->left);
        }
        else if(left_node->right != NULL || right_node->left != NULL)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Node* root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(2);
    root->left->left = NewNode(3);
    root->right->right = NewNode(3);
    root->left->right = NewNode(4);
    root->right->left = NewNode(4);
    
    cout << "Is tree symmetric(Iterative)? " << isSymmetricIter(root) << endl;
    cout << "Is tree symmetric(Recursive)? " << isSymmetricRec(root) << endl;

    return 0;
}
/* Binary Tree
      1
     / \
    /   \
   2     2
  / \   / \
 3  4  4   3
Expected output: Is tree symmetric(Iterative)? 1
                 Is tree symmetric(Recursive)? 1
*/