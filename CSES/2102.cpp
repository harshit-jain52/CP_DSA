#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int ALP = 26;

struct Node
{
    vector<int>next,go;
    vector<int>stop;
    int par, suff_link, dict_link;
    char par_c;

    Node(int p = -1, char ch = '$') : par(p), par_c(ch)
    {
        next.assign(ALP, -1);
        go.assign(ALP, -1);
        suff_link = dict_link = -1;
    }
};

vector<Node> trie(1);

void insert(string const &s, const int &idx)
{
    int v = 0;
    for (char c : s)
    {
        if (trie[v].next[c-'a'] == -1)
        {
            trie[v].next[c-'a'] = trie.size();
            trie.emplace_back(v, c);
        }
        v = trie[v].next[c-'a'];
    }
    trie[v].stop.push_back(idx);
}

int go(int v, char c); 
int get_suff_link(int v); // Suffix Link/Failure Link for a vertex v is an edge that points to the longest proper suffix of the string corresponding to the vertex v.
int get_dict_link(int v); // Dictionary Link/Exit Link for a vertex v is an edge that points to the longest proper suffix of the string corresponding to the vertex v that is a word in the dictionary.

int go(int v, char c)
{
    if (trie[v].go[c-'a'] == -1)
    {
        if (trie[v].next[c-'a'] != -1) trie[v].go[c-'a'] = trie[v].next[c-'a'];
        else trie[v].go[c-'a'] = ((v==0)? 0 : go(get_suff_link(v), c));
    }
    return trie[v].go[c-'a'];
}

int get_suff_link(int v)
{
    if (trie[v].suff_link == -1)
    {
        if (v == 0 || trie[v].par == 0) trie[v].suff_link = 0;
        else trie[v].suff_link = go(get_suff_link(trie[v].par), trie[v].par_c);
    }
    return trie[v].suff_link;
}

int get_dict_link(int v)
{
    if (trie[v].dict_link == -1)
    {
        int suff_link = get_suff_link(v);
        if (v == 0 || suff_link == 0) trie[v].dict_link = 0;
        else trie[v].dict_link = (!trie[suff_link].stop.empty() ? suff_link : get_dict_link(suff_link));
    }
    return trie[v].dict_link;
}

int main()
{
    FASTIO
    string text; cin >> text;
    int k; cin >> k;

    for(int i=0;i<k;i++){
        string pat; cin >> pat;
        insert(pat,i);
    }

    vector<bool> exists(k, false);
    int v = 0;
    map<int,bool>seen;
    for (char c : text) {
        v = go(v, c);
        for (int u = v; u != 0 && !seen[u]; u = get_dict_link(u)) {
            for (int idx : trie[u].stop) {
                exists[idx] = true;
            }
            seen[u]=true;
        }
    }

    for (int i=0;i<k;i++) {
        cout << (exists[i]?"YES":"NO") << endl;
    }
}