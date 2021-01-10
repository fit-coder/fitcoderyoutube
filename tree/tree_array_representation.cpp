/*
** @Author: Sandeep Thapar
**
** Array representation of a binary tree
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
using namespace std;

void set_left(char tree[], char val, int parent)
{
    tree[2*parent + 1] = val;
}

void set_right(char tree[], char val, int parent)
{
    tree[2*parent + 2] = val;
}

int main()
{
    int N = 15;
    char tree[N] = {0};
    
    tree[0] = 'M';
    set_left(tree, 'P', 0);
    set_right(tree, 'Q', 0);
    set_left(tree, 'A', 1);
    set_right(tree, 'D', 1);
    set_left(tree, 'B', 2);
    set_right(tree, 'C', 2);
    set_right(tree, 'W', 6);

    for (int i=0; i < N; i++)
    {
        if (tree[i] == '\0')
            cout << "-" << " ";
        else
            cout << tree[i] << " ";
    }
    return 0;
}

