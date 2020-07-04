/* Binary Tree can be uniquely constructed from Inorder and Levelorder traversals. The first Node of Levelorder traversal
   is Root of the tree. Finding its position from inorder we can separate left and right subtrees. Then modify the 
   Levelorder traversal such that it contains only elements of left and right subtrees respectively and continue this
   recursively for all Nodes.
   Algorithm:
   ->if start_index > end_index for inorder(i.e. no subtree exists)
      ->return NULL
   ->create NewNode with data at levelorder_index.
   ->if start_index != end_index for inorder(i.e. subtree exists)
      ->search inorder index for data equivalent to current leveltorder data.
      ->Modify levelorder for left subtree.
      ->pass left subtree to function.
      ->Modify levelorder for right subtree.
      ->pass right subtree to function.
   ->return the created NewNode.
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

int search(int arr[],int start,int end,int data)
{
    for(int i = start;i <= end;i++)
    {
        if(arr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

int *modified_levelorder(int inorder[],int levelorder[],int start,int end,int n)
{
    int *arr = new int[end-start+1],j = 0;
    for(int i = 0;i < n;i++)
    {
        if(search(inorder,start,end,levelorder[i]) != -1)
        {
            arr[j] = levelorder[i];               // Add those elements of Levelorder (in same order)
            j++;                                  // that exists in given subarray part of inorder.
        }
    }
    return arr;
}

Node* tree(int inorder[],int levelorder[],int inorder_start,int inorder_end,int n)
{
    if(inorder_start > inorder_end)
    {
        return NULL;
    }

    Node* current = NewNode(levelorder[0]);
    
    if(inorder_start != inorder_end)
    {
        int inorder_index = search(inorder,inorder_start,inorder_end,current->data);
        int *level_left = modified_levelorder(inorder,levelorder,inorder_start,inorder_index-1,n);
        current->left = tree(inorder,level_left,inorder_start,inorder_index-1,n);
        int *level_right = modified_levelorder(inorder,levelorder,inorder_index+1,inorder_end,n);
        current->right = tree(inorder,level_right,inorder_index+1,inorder_end,n);
    }

    return current;
}

int main()
{
    int inorder[] = {4,8,2,5,1,6,10,9,3,7};
    int levelorder[] = {1,2,3,4,5,6,7,8,9,10};
    Node* root = tree(inorder,levelorder,0,(sizeof(inorder)/sizeof(inorder[0])-1),sizeof(levelorder)/sizeof(levelorder[0]));
    cout << "Binary Tree Created" << endl;
    cout << "Inorder traversal of created tree : ";
    in_order(root);
    cout << endl;
    cout << "Levelorder traversal of created tree : ";
    level_order(root);
    cout << endl;

    return 0;
}
/*Expected output: Binary Tree Created
                   Inorder traversal of created tree : 4 8 2 5 1 6 10 9 3 7 
                   Levelorder traversal of created tree : 1 2 3 4 5 6 7 8 9 10
   Binary Tree
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
*/