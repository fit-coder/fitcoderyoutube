/*
** @Author: Sandeep Thapar
**
** Check if given array can represent a preorder traversal of a binary search tree
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <vector>
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

bool validate_bst_from_preorder(vector<int>& preorder)
{
    stack<int> st;
    int root = INT_MIN;
    for (int i=0; i < preorder.size(); i++)
    {
        while (!st.empty() && preorder[i] > st.top())
        {
            root = st.top();
            st.pop();
        }
        if (preorder[i] < root)
            return false;
        st.push(preorder[i]);
    }
    return true;
}

int main()
{
    vector<int> v1 = {2,4,3};
    vector<int> v2 = {2,4,1};
    vector<int> v3 = {44,22,11,33,66,55,77,88};
    vector<int> v4 = {44,22,11,66,55,33,77,88};

    cout << "Is {2,4,3} valid preorder traversal of a BST: ";
    cout << validate_bst_from_preorder(v1) << endl;
    
    cout << "Is {2,4,1} valid preorder traversal of a BST: ";
    cout << validate_bst_from_preorder(v2) << endl;

    cout << "Is {44,22,11,33,66,55,77,88} valid preorder traversal of a BST: ";
    cout << validate_bst_from_preorder(v3) << endl;

    cout << "Is {44,22,11,66,55,33,77,88} valid preorder traversal of a BST: ";
    cout << validate_bst_from_preorder(v4) << endl;
    
    return 0;
}




