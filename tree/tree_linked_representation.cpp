/*
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
** Please subscribe if you like the content
*/

#include <iostream>
using namespace std;

struct Node
{
    char val;
    Node* left;
    Node* right;

    Node(char data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    Node* root = new Node('M');
    root->left = new Node('P');
    root->right = new Node('Q');
    root->left->left = new Node('A');
    root->left->right = new Node('D');
    root->right->left = new Node('B');
    root->right->right = new Node('C');
    root->right->right->right = new Node('W');
    return 0;
}