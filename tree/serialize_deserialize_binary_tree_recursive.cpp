/*
** @Author: Sandeep Thapar
**
** Serialization is to store tree in a file so that it can be later restored.
** The structure of tree must be maintained. Deserialization is reading tree back from file.
** Here I have implemented DFS approach (preorder) and serialized tree into string
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <sstream>

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

void postorder_traversal(TreeNode *root)
{
    if (root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->val << " ";
}

string serialize(TreeNode* root)
{
    string s;
    if (root == NULL)
        s += "#,";
    else
    {
        s += to_string(root->val) + ",";
        s += serialize(root->left);
        s += serialize(root->right);
    }
    return s;
}

TreeNode* deserial(stringstream& ss)
{
    string val;
    getline(ss, val, ',');
    if (val == "#")
        return NULL;
    TreeNode* root = new TreeNode(stoi(val));
    root->left = deserial(ss);
    root->right = deserial(ss);
    return root;
}

TreeNode* deserialize(string data)
{
    stringstream ss(data);
    return deserial(ss);
}

int main()
{
    TreeNode* root = new TreeNode(15);
    root->left = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(18);
    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(6);

    cout << "Serialize Binary Tree to: ";
    string s = serialize (root);
    cout << s << endl;
    
    cout << "De-Serialize Binary Tree from: " << s << endl;
    TreeNode *r = deserialize(s);
    cout << "Inorder Traversal:   ";
    inorder_traversal(r);
    cout << endl;
    cout << "Postorder Traversal: ";
    postorder_traversal(r);
    cout << endl;

    return 0;
}
