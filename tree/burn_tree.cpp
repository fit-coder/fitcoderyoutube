/*
** @Author: Sandeep Thapar
**
** Given a binary tree (unique nodes) and a start node from where the tree will start to burn.
** Find the time (in minutes) that it will take to burn the whole tree.
** It is given that it takes 1 minute for the fire to travel from the burning node to its adjacent
** node and burn down the adjacent node.
**
** For video explanation, please refer to my Youtube channel in the link below:
** Channel: youtube.com/fitcoder
** Tree Playlist: https://www.youtube.com/playlist?list=PLFj4kIJmwGu2VDN0qKVMmCbEeGBEpXzkX
**
** Please subscribe to the channel if you find this helpful
*/

#include <bits/stdc++.h>
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

// BFS traversal to set parent of each tree node
void setParents(TreeNode* root, char start, TreeNode*& startNode, 
                unordered_map<TreeNode*,TreeNode*>& umParent)
{
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        if (node->val == start)
            startNode = node;
        if (node->left)
        {
            umParent[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            umParent[node->right] = node;
            q.push(node->right);
        }
    }
}

int burnTree(TreeNode* root, int start)
{
    TreeNode* startNode = NULL;
    unordered_map<TreeNode*, TreeNode*> umParent; // child -> parent

    setParents(root, start, startNode, umParent);

    queue<pair<TreeNode*,int>> q; // {node, burnTime}
    q.push({startNode, 0});

    unordered_set<TreeNode*> visited;
    visited.emplace(startNode);

    int treeBurnTime = 0;
    while (!q.empty())
    {
        auto [node, time] = q.front();
        q.pop();
        treeBurnTime = max(treeBurnTime, time);
        // go LEFT
        if (node->left && visited.find(node->left) == visited.end())
        {
            q.push({node->left, time + 1});
            visited.emplace(node->left);
        }
        // go RIGHT
        if (node->right && visited.find(node->right) == visited.end())
        {
            q.push({node->right, time + 1});
            visited.emplace(node->right);
        }
        // go UP
        if (umParent.find(node) != umParent.end() && visited.find(umParent[node]) == visited.end())
        {
            q.push({umParent[node], time + 1});
            visited.emplace(umParent[node]);
        }
    }
    return treeBurnTime;
}

int main()
{
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('D');
    root->left->left = new TreeNode('H');
    root->left->right = new TreeNode('L');
    root->left->left->left = new TreeNode('K');
    root->left->left->right = new TreeNode('P');
    root->right = new TreeNode('Z');
    root->right->left = new TreeNode('B');
    root->right->left->right = new TreeNode('C');

    int treeBurnTime = burnTree(root, 'A');
    cout << "Time taken to burn the tree starting from A: " << treeBurnTime << endl;

    treeBurnTime = burnTree(root, 'D');
    cout << "Time taken to burn the tree starting from D: " << treeBurnTime << endl;
 
    treeBurnTime = burnTree(root, 'C');
    cout << "Time taken to burn the tree starting from C: " << treeBurnTime << endl;

    return 0;
}
