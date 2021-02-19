/*
** @Author: Sandeep Thapar
**
** Find top view, bottom view of a binary Tree using recursive method
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
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

void top_view(TreeNode *node, map<int, pair<char,int>>& m, int dist, int level)
{
    if (node == NULL)
       return;
    if (m.count(dist) == 0 || m[dist].second > level)
        m[dist] = make_pair(node->val, level);

    top_view(node->left, m, dist-1, level + 1);
    top_view(node->right, m, dist+1, level + 1);
}

void bottom_view(TreeNode *node, map<int, pair<char,int>>& m, int dist, int level)
{
    if (node == NULL)
       return;
    if (m.count(dist) == 0 || m[dist].second < level)
        m[dist] = make_pair(node->val, level);

    bottom_view(node->left, m, dist-1, level + 1);
    bottom_view(node->right, m, dist+1, level + 1);
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

    map<int, pair<char,int>> m;
    cout << "Top View of the tree (Recursive method): ";
    top_view(root, m, 0, 0);
    for (auto i : m)
        cout << i.second.first << " ";
    cout << endl;
    
    m.clear();
    cout << "Bottom View of the tree (Recursive method): ";
    bottom_view(root, m, 0, 0);
    for (auto i : m)
        cout << i.second.first << " ";
    cout << endl;

    return 0;
}

