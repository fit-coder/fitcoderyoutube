/*
** @Author: Sandeep Thapar
**
** Find diagonal traversal of a binary Tree
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode
{
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

void diagonal_traversal(TreeNode *root)
{
    if (root == NULL)
       return;
    unordered_map<int, vector<char>> um;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    int max_dd = 0;
    while (!q.empty())
    {
        TreeNode* curr = q.front().first;
        int dd = q.front().second;
        q.pop();
        max_dd = max(max_dd, dd);
        um[dd].emplace_back(curr->val);
        if (curr->left != NULL)
            q.push({curr->left, dd+1});
        if (curr->right != NULL)
            q.push({curr->right, dd});
    }
    for (int dd=0; dd <= max_dd; dd++)
    {
        for (auto i  : um[dd])
            cout << i << " ";
    }
}

int main()
{
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('D');
    root->left->left = new TreeNode('H');
    root->left->left->right = new TreeNode('K');
    root->left->right = new TreeNode('L');
    root->right = new TreeNode('Z');
    root->right->left = new TreeNode('M');
    root->right->right = new TreeNode('C');
    root->right->right->left = new TreeNode('P');

    cout << "Diagonal Traversal of the tree: ";
    diagonal_traversal(root);

    return 0;
}


