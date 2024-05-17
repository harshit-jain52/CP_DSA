#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 3e5 + 5;

int trie[N][26];
int pref[N];
ll pairct[N];
int ct = 0;

void insert(string &s)
{
    int node = 0;

    for (char c : s)
    {
        if (trie[node][c - 'a'] == 0)
        {
            trie[node][c - 'a'] = ++ct;
            // cout << node << " "<<ct<<" "<<c<<endl;
        }

        node = trie[node][c - 'a'];
        pref[node]++;
    }
}

ll dfs(int node, int len)
{
    if (node == 0)
        return 0;

    ll base = (pref[node] * 1LL * (pref[node] - 1)) / 2;
    ll child = 0;
    for (int i = 0; i < 26; i++)
        child += dfs(trie[node][i], len + 1);
    pairct[len] += (base - child);
    return base;
}

int main()
{
    FASTIO
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        insert(s);
    }

    for (int i = 0; i < 26; i++)
        dfs(trie[0][i], 1);

    // for(int i=1;i<=ct;i++) cout << pref[i]<<endl;
    ll ans = 0;
    for (int i = 1; i < N; i++)
    {
        ans += pairct[i] * i;
    }
    cout << ans;
}