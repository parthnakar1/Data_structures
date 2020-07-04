/* Binary Tree can be constructed uniquely from its Inorder and Preorder traversals. The basic idea is to find current
   Node and its position in both traversals and separate left and right subtrees. This is done recursively for each Node
   in the tree until all Nodes are assigned their respective children.
   Algorithm: 
   ->static int preorder_index = 0(Static variable is used since we traverse through each Node only once)
   ->if start_index > end_index for inorder(i.e. no subtree exists)
      ->return NULL
   ->create NewNode with data at preorder_index. Increment preorder_index.
   ->if start_index != end_index for inorder(i.e. subtree exists)
      ->search inorder index for data equivalent to current preorder data.
      ->pass left subtree to function.
      ->pass right subtree to function.
   ->return the created NewNode.
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

void pre_order(Node* root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        pre_order(root->left);
        pre_order(root->right);
    }
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

int search(int arr[],int start,int end,int data)
{
    int i;
    for(i = start;i <= end;i++)
    {
        if(arr[i] == data)
        {
            break;
        }
    }
    return i;
}

Node* tree(int inorder[],int preorder[],int inorder_start, int inorder_end)
{
    static int preorder_index = 0;

    if(inorder_start > inorder_end)
    {
        return NULL;
    }
    
    Node* current = NewNode(preorder[preorder_index]);
    preorder_index++;

    if(inorder_start != inorder_end)
    {
        int inorder_index = search(inorder,inorder_start,inorder_end,current->data);
        current->left = tree(inorder,preorder,inorder_start,inorder_index-1);
        current->right = tree(inorder,preorder,inorder_index+1,inorder_end);   
    }
    
    return current;
}

int main()
{
    int inorder[] = {4,8,2,5,1,6,10,9,3,7};
    int preorder[] = {1,2,4,8,5,3,6,9,10,7};
    Node* root = tree(inorder,preorder,0,(sizeof(inorder)/sizeof(inorder[0])-1));
    cout << "Binary Tree Created" << endl;
    cout << "Inorder traversal of created tree : ";
    in_order(root);
    cout << endl;
    cout << "Preorder traversal of created tree : ";
    pre_order(root);
    cout << endl;

    return 0;
}
/*Expected output: Binary Tree Created
                   Inorder traversal of created tree : 4 8 2 5 1 6 10 9 3 7 
                   Preorder traversal of created tree : 1 2 4 8 5 3 6 9 10 7
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