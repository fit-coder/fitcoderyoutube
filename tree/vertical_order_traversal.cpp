/*
** @Author: Sandeep Thapar
**
** Find vertical order traversal of a binary Tree - O(n) method
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

void vertical_order_traversal(TreeNode *root)
{
    if (root == NULL)
       return;
    unordered_map<int, vector<char>> um;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    int min_dist = 0, max_dist = 0;
    while (!q.empty())
    {
        TreeNode* curr = q.front().first;
        int dist = q.front().second;
        q.pop();
        min_dist = min(min_dist, dist);
        max_dist = max(max_dist, dist);
        um[dist].emplace_back(curr->val);
        if (curr->left != NULL)
            q.push({curr->left, dist-1});
        if (curr->right != NULL)
            q.push({curr->right, dist+1});
    }
    while (min_dist <= max_dist)
    {
        if (um.find (min_dist) != um.end())
        {
            for (auto i  : um[min_dist])
                cout << i << " ";
        }
        ++min_dist;
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

    cout << "Vertical order Traversal of the tree: ";
    vertical_order_traversal(root);

    return 0;
}


