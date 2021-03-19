/*
** @Author: Sandeep Thapar
**
** Delete a node from a binary search tree
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

TreeNode* delete_node(TreeNode *root, int val)
{
    if (root == NULL)
        return NULL;
    if (val < root->val)
        root->left = delete_node (root->left, val);
    else if (val > root->val)
        root->right = delete_node (root->right, val);
    else
    {
        // no child
        if (root->left == NULL && root->right == NULL)
        {
            delete(root);
            return NULL;
        }
        // 1 child
        else if (root->left == NULL || root->right == NULL)
        {
            TreeNode *temp = root->left ? root->left : root->right;
            delete(root);
            return temp;
        }
        // 2child
        else if (root->left != NULL && root->right != NULL)
        {
            TreeNode *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->val = temp->val;
            root->right = delete_node(root->right, root->val);
        }
    }
    return root;
}

int main()
{
    vector<int> v = {11,7,9,4,15,12,1,10,25,20,22};
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

    cout << "Delete 10 from the BST" << endl;
    root = delete_node(root, 10);
    cout << "Inorder Traversal of BST: ";
    inorder_traversal(root);
    cout << endl << endl;

    cout << "Delete 4 from the BST" << endl;
    root = delete_node(root, 4);
    cout << "Inorder Traversal of BST: ";
    inorder_traversal(root);
    cout << endl << endl;

    cout << "Delete 15 from the BST" << endl;
    root = delete_node(root, 15);
    cout << "Inorder Traversal of BST: ";
    inorder_traversal(root);
    cout << endl << endl;

    return 0;
}



