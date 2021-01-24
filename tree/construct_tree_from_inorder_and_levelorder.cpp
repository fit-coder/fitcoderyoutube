/*
** @Author: Sandeep Thapar
**
** Construct a binary tree from given inorder and levelorder traversal - Recursive method
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
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

void inorder_traversal(TreeNode *node)
{
    if (node == NULL)
        return;
    inorder_traversal(node->left);
    cout << node->val << " ";
    inorder_traversal(node->right);
}

void levelorder_traversal(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        cout << curr->val << " ";
        q.pop();
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

TreeNode* construct_tree(vector<char>& inorder, 
                         unordered_map<char,int>& levelorderMap,
                         int inStart, int inEnd)
{
    if (inStart > inEnd)
        return NULL;

    // find node with minimum index in level-order traversal
    // That would be the root node of inorder[start, end]
    int inIndex = inStart;
    for (int j = inStart + 1; j <= inEnd; j++)
    {
        if (levelorderMap[inorder[j]] < levelorderMap[inorder[inIndex]])
            inIndex = j;
    }
    
    TreeNode* node = new TreeNode(inorder[inIndex]);
    if (inStart == inEnd)
        return node;

    // recursively construct the left and right subtree
    node->left = construct_tree(inorder, levelorderMap, inStart, inIndex - 1);
    node->right = construct_tree(inorder,  levelorderMap, inIndex + 1, inEnd);

    return node;
}

int main()
{
    vector<char> inorder = {'H','D','P','L','A','Z','C','E'};
    vector<char> levelorder = {'A','D','Z','H','L','C','P','E'};

    // construct a value-to-index map for levelorder traversal
    unordered_map<char,int> levelorderMap;
    for (int i=0; i < levelorder.size(); i++)
        levelorderMap[levelorder[i]] = i;

    TreeNode* root = construct_tree(inorder, levelorderMap, 0, inorder.size()-1);
    
    cout << "Tree constructed" << endl;
    cout << "Inorder traversal of the constructed tree: ";
    inorder_traversal(root);
    cout << endl;

    cout << "Levelorder traversal of the constructed tree: ";
    levelorder_traversal(root);
    cout << endl;
    return 0;
}

