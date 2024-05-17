#include <bits/stdc++.h>
using namespace std;

const int WMAX = 1e6 + 5;
int trie[WMAX][26];
int stop[WMAX];
int pref[WMAX];
int node_count = 0;
/*
A trie is a tree-like data structure that stores strings.
Each node is a string, and each edge is a character.

The root is the empty string, and every node is represented by the characters along the path from the root to that node.
This means that every prefix of a string is an ancestor of that string's node
*/

void insert(string &word)
{
    // Node 0 has 26 children - a through z
    int node = 0;
    for (char c : word)
    {
        if (trie[node][c - 'a'] == 0) // If a node with the current char doesn't exist create one
            trie[node][c - 'a'] = ++node_count;

        node = trie[node][c - 'a']; // Move down the path in the trie.
        pref[node]++;
    }
    stop[node]++; // Mark the ending node so we know it's a dictionary word
}