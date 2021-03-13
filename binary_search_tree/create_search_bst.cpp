/*
** @Author: Sandeep Thapar
**
** Create a binary search tree from given set of numbers.
** Search a number in a binary search tree
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

void inorder_traversal(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    cout << root->val << " ";
    inorder_traversal(root->right);
}

TreeNode* insert (TreeNode *root, int val)
{
    if (root == NULL)
        root = new TreeNode(val);
    else if (val < root->val)
        root->left = insert (root->left, val);
    else
        root->right = insert (root->right, val);
    return root;
}

bool search(TreeNode *root, int val)
{
    if (root == NULL)
        return false;
    if (root->val == val)
        return true;
    if (val < root->val)
        return search (root->left, val);
    return search (root->right, val);
}

int main()
{
    vector<int> v = {11,7,9,4,15,12,1,10,25,20};
    TreeNode* root = NULL;
    cout << "BST created from : ";
    for (int i : v)
    {
        cout << i << " ";
        if (root == NULL)
            root = insert(root, i);
        else
            insert (root, i);
    }
    cout << endl;
    
    cout << "Inorder Traversal of BST: ";
    inorder_traversal(root);
    cout << endl << endl;
    
    cout << "Is 4 present in the BST: ";
    cout << search(root, 4) << endl;
    cout << "Is 10 present in the BST: ";
    cout << search(root, 10) << endl;
    cout << "Is 12 present in the BST: ";
    cout << search(root, 12) << endl;
    cout << "Is 16 present in the BST: ";
    cout << search(root, 16) << endl;

    return 0;
}



