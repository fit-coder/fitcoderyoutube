/*
** @Author: Sandeep Thapar
**
** Trie - A trie is a tree data structure used to efficiently store and
** reTRIEve keys in a dataset of strings.
**
** For video explanation, please refer to my Youtube channel in the link below:
** Channel: youtube.com/fitcoder
** Trie Playlist: https://www.youtube.com/playlist?list=PLFj4kIJmwGu0IGe4DyknXdGCzZNGD_2HP
**
** Please subscribe to the channel if you find this helpful
*/

#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode
{
    TrieNode *child[26];
    bool isWord;

    TrieNode()
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
            child[i] = NULL;
        isWord = false;
    }
};

// Inserts a word into the trie
void insert(TrieNode *node, string word)
{
    for (char c : word)
    {
        if (node->child[c - 'a'] == NULL)
            node->child[c - 'a'] = new TrieNode();
        node = node->child[c - 'a'];
    }
    node->isWord = true;
}

// function to print the contents of Trie
void print(TrieNode *node, const string &prefix)
{
    if (node->isWord == true)
    {
        cout << prefix << endl;
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if (node->child[i] != NULL)
        {
            char ch = 'a' + i;
            print(node->child[i], prefix + ch);
        }
    }
}

int main()
{
    vector<string> words = {"there", "their", "answer", "any", "bye"};
    TrieNode *root = new TrieNode();

    for (string word : words)
    {
        insert(root, word);
    }
    string prefix = "";
    print(root, prefix);
    return 0;
}