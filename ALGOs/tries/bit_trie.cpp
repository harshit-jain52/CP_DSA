#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> trie(1, vector<int>(2));

void insert(int num)
{
    int node = 0;
    for (int i = 30; i >= 0; i--) // all nums are stored as uniform-length binary strings
    {
        int bit = (num >> i) & 1;
        if (!trie[node][bit])
        {
            trie.push_back(vector<int>(2));
            trie[node][bit] = trie.size() - 1;
        }
        node = trie[node][bit];
    }
}