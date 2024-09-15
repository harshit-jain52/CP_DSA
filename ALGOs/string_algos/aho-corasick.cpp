#include <bits/stdc++.h>
using namespace std;
const int ALP = 26;

// Trie Implementation
struct Node
{
    vector<int> next, go;
    bool stop;
    int par, suff_link;
    char par_c;

    Node(int p = -1, char ch = '$') : par(p), par_c(ch)
    {
        next.assign(ALP, -1);
        go.assign(ALP, -1);
        stop = false;
        suff_link = -1;
    }
};

vector<Node> trie(1);

void insert(string const &s)
{
    int v = 0;
    for (char c : s)
    {
        if (trie[v].next[c - 'a'] == -1)
        {
            trie[v].next[c - 'a'] = trie.size();
            trie.emplace_back(v, c);
        }
        v = trie[v].next[c - 'a'];
    }
    trie[v].stop = true;
}

// Constructing the Aho-Corasick Automaton
int go(int v, char c);    // Returns the next vertex after moving from vertex v with character c
int get_suff_link(int v); // Suffix Link/Failure Link for a vertex v is an edge that points to the longest proper suffix of the string corresponding to the vertex v.

int go(int v, char c)
{
    if (trie[v].go[c - 'a'] == -1)
    {
        if (trie[v].next[c - 'a'] != -1)
            trie[v].go[c - 'a'] = trie[v].next[c - 'a'];
        else
            trie[v].go[c - 'a'] = ((v == 0) ? 0 : go(get_suff_link(v), c));
    }
    return trie[v].go[c - 'a'];
}

int get_suff_link(int v)
{
    if (trie[v].suff_link == -1)
    {
        if (v == 0 || trie[v].par == 0)
            trie[v].suff_link = 0;
        else
            trie[v].suff_link = go(get_suff_link(trie[v].par), trie[v].par_c);
    }
    return trie[v].suff_link;
}