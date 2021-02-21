/*
** @Author: Sandeep Thapar
**
** Find top view, bottom view of a binary Tree using iterative method
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <queue>
#include <map>
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

void top_view(TreeNode *root)
{
    if (root == NULL)
       return;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    map<int,char> m;
    
    while (!q.empty())
    {
        TreeNode* curr = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (m.count(dist) == 0)
            m[dist] = curr->val;

        if (curr->left != NULL)
            q.push({curr->left, dist-1});
        if (curr->right != NULL)
            q.push({curr->right, dist+1});
    }
    for (auto i : m)
        cout << i.second << " ";
}

void bottom_view(TreeNode *root)
{
    if (root == NULL)
       return;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    map<int,char> m;

    while (!q.empty())
    {
        TreeNode* curr = q.front().first;
        int dist = q.front().second;
        q.pop();

        m[dist] = curr->val;

        if (curr->left != NULL)
            q.push({curr->left, dist-1});
        if (curr->right != NULL)
            q.push({curr->right, dist+1});
    }
    for (auto i : m)
        cout << i.second << " ";
}

int main()
{
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('D');
    root->left->left = new TreeNode('H');
    root->left->right = new TreeNode('L');
    root->left->right->left = new TreeNode('K');
    root->left->right->right = new TreeNode('P');
    root->right = new TreeNode('Z');
    root->right->right = new TreeNode('C');
    root->right->right->right = new TreeNode('B');

    cout << "Top View of the tree (Iterative method): ";
    top_view(root);
    cout << endl;
    
    cout << "Bottom View of the tree (Iterative method): ";
    bottom_view(root);

    return 0;
}

