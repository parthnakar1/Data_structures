/* Array implementataion is a form of sequential based representataion of binary tree. It is efficient for a perfect
   binary tree. In the code below, SetChild and ShowChild are two methods of class b_tree. The left and right children
   are at (2*i) and (2*i+1) respectively.
*/
#include<iostream>
using namespace std;

class b_tree
{
    public:
    int arr[8];
    void SetChild(int index,int data,char pos);
    void ShowChild(int index,char pos);
};

void b_tree::SetChild(int index,int data,char pos)
{
    if(index == 0)
    {
        if(pos == 'l')
        {
            arr[1] = data;
        }
        else
        {
            arr[2] = data;
        }
    }
    else
    {
        if(pos == 'l')
        {
            arr[2*index] = data;
        }
        else
        {
            arr[2*index + 1] = data;
        }
    }
}

void b_tree::ShowChild(int index,char pos)
{
    if(index == 0)
    {
        if(pos == 'l')
        {
            cout << arr[1];
        }
        else
        {
            cout << arr[2];
        }
    }
    else
    {
        if(pos == 'l')
        {
            cout << arr[2*index];
        }
        else
        {
            cout << arr[2*index + 1];
        }
    }
}

int main()
{
    b_tree b1;
    b1.arr[0] = 1;
    b1.SetChild(0,2,'l');
    b1.SetChild(0,3,'r');
    b1.SetChild(1,4,'l');
    b1.SetChild(1,5,'r');
    b1.SetChild(2,6,'l');
    b1.SetChild(2,7,'r');
    cout << "Parent : 1 - LeftChild : ";
    b1.ShowChild(0,'l');
    cout << endl;
    cout << "Parent : 2 - RightChild : ";
    b1.ShowChild(1,'r');
    cout << endl;
    cout << "Parent : 3 - LeftChild : ";
    b1.ShowChild(2,'l');
    cout << endl;

    return 0;
}
/* Binary tree
     1
    / \
   /   \
  2     3
 / \   / \
4   5 6   7
Expected output: Parent : 1 - LeftChild : 2
                 Parent : 2 - RightChild : 5
                 Parent : 3 - LeftChild : 6
*/