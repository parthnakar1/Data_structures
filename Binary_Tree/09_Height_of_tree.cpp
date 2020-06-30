/* The height of a Binary Tree is the number of levels of nodes from root Node being the topmost to leaf Nodes.
   RECURSIVE Algorithm:
   ->if root == NULL
      ->return 0
   ->else
      ->return max(height(left_subtree),height(right_subtree))+1
   ITERATIVE Algorithm:
   ->if root == NULL
      ->return 0
   ->else
      ->Push root into q.
      ->While q is not empty.
         ->cur_level_size = q.size()
         ->While cur_level_size
           ->Node* temp = q.front()
           ->Push children of temp into q.      //This takes care that only 1 level is moved each time.
           ->cur_level_size--
         ->height++
      ->return height
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

int height_rec(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return(max(height_rec(root->left),height_rec(root->right))+1);
    }
}

int height_iter(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        queue<Node*> q;
        Node* temp = NULL;
        q.push(root);
        int height = 0, cur_level_size;
        while(!q.empty())
        {
            cur_level_size = q.size();
            while(cur_level_size)
            {
                temp = q.front();
                if(temp->left != NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right != NULL)
                {
                    q.push(temp->right);
                }
                q.pop();
                cur_level_size--;
            }
            height++;
        }
        return height;
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
    cout << "Height(Iterative) = " << height_iter(root) << endl;
    cout << "Height(Recursive) = " << height_rec(root) << endl;

    return 0;
}
/*    Binary Tree        Depth
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
Expected output: Height(Iterative) = 5
                 Height(Recursive) = 5
*/