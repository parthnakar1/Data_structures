/* Binary Tree can be constructed uniquely from its Inorder and Postorder traversals. This is done by finding the
   current Node and its position in both traversals and separate left and right subtrees. This is achieved following
   same thing recursively until all Nodes are assigned their respective children.
   Algorithm:
   ->static int postorder_index = len(postorder) - 1 (Static variable is used since we traverse through all Nodes only once)
   ->if start_index > end_index for inorder(i.e. no subtree exists)
      ->return NULL
   ->create NewNode with data at postorder_index. Increment postorder_index.
   ->if start_index != end_index for inorder(i.e. subtree exists)
      ->search inorder index for data equivalent to current postorder data.
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

void in_order(Node* root)
{
    if(root != NULL)
    {
        in_order(root->left);
        cout << root->data << " ";
        in_order(root->right);
    }
}

void post_order(Node* root)
{
    if(root != NULL)
    {
        post_order(root->left);
        post_order(root->right);
        cout <<  root->data << " ";
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

Node* tree(int inorder[],int postorder[],int inorder_start,int inorder_end,int n)
{
    static int postorder_index = n;

    if(inorder_start > inorder_end)
    {
        return NULL;
    }

    Node* current = NewNode(postorder[postorder_index]);
    postorder_index--;

    if(inorder_start != inorder_end)
    {
        int inorder_index = search(inorder,inorder_start,inorder_end,current->data);
        current->right  = tree(inorder,postorder,inorder_index+1,inorder_end,n);
        current->left = tree(inorder,postorder,inorder_start,inorder_index-1,n);
    }

    return current;
}

int main()
{
    int inorder[] = {4,8,2,5,1,6,10,9,3,7};
    int postorder[] = {8,4,5,2,10,9,6,7,3,1};
    Node* root = tree(inorder,postorder,0,(sizeof(inorder)/sizeof(inorder[0])-1),(sizeof(postorder)/sizeof(postorder[0])-1));
    cout << "Binary Tree Created" << endl;
    cout << "Inorder traversal of created tree : ";
    in_order(root);
    cout << endl;
    cout << "Postorder traversal of created tree : ";
    post_order(root);
    cout << endl;

    return 0;
}
/*Expected output: Binary Tree Created
                   Inorder traversal of created tree : 4 8 2 5 1 6 10 9 3 7 
                   Postorder traversal of created tree : 8 4 5 2 10 9 6 7 3 1
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