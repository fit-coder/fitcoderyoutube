/*
** @Author: Sandeep Thapar
**
** Check if two elements are present in a BST that have sum equal to given target sum.
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <stack>
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

void push_left_nodes(stack<TreeNode*>& st1, TreeNode* node)
{
    while (node)
    {
        st1.push(node);
        node = node->left;
    }
}

void push_right_nodes(stack<TreeNode*>& st2, TreeNode* node)
{
    while (node)
    {
        st2.push(node);
        node = node->right;
    }
}

// Using 2-pointer approach
bool find_target(TreeNode* root, int k)
{
    if (root == NULL)
        return false;
    stack<TreeNode *> st1, st2;
    push_left_nodes(st1, root);
    push_right_nodes(st2, root);
    TreeNode *low = st1.top();
    TreeNode *high = st2.top();
    while (low && high && low->val < high->val)
    {
        int sum = low->val + high->val;
        if (sum < k) // increase low
        {
            push_left_nodes(st1, low->right);
            low = st1.top();
            st1.pop();
        }
        else if (sum > k) // decrease high
        {
            push_right_nodes(st2, high->left);
            high = st2.top();
            st2.pop();
        }
        else
            return true;
    }
    return false;
}

int main()
{
    TreeNode *root = new TreeNode (15);
    root->left = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(17);
    root->right->left->right = new TreeNode(19);

    int target = 36;
    cout << "Are there any two elements in BST having sum = 36 ? : ";
    cout << find_target(root, target) << endl;

    target = 22;
    cout << "Are there any two elements in BST having sum = 22 ? : ";
    cout << find_target(root, target) << endl;

    target = 18;
    cout << "Are there any two elements in BST having sum = 18 ? : ";
    cout << find_target(root, target) << endl;
    
    target = 13;
    cout << "Are there any two elements in BST having sum = 13 ? : ";
    cout << find_target(root, target) << endl;
    return 0;
}




