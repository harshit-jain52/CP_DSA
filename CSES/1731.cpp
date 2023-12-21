#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

const int WMAX = 1e6 + 5;
int trie[WMAX][26];
bool stop[WMAX];
int node_count = 0;

void insert(string &word)
{
    int node = 0;
    for (char c : word)
    {
        if (trie[node][c - 'a'] == 0)
            trie[node][c - 'a'] = ++node_count;

        node = trie[node][c - 'a'];
    }
    stop[node] = true;
}

int main()
{
    FASTIO
    string str;
    cin >> str;
    int k;
    cin >> k;
    while (k--)
    {
        string word;
        cin >> word;
        insert(word);
    }

    int n = str.size();
    vector<int> dp(n + 1, 0); // dp[i] = no. of ways s[i..n] can be formed
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        int node = 0;
        for (int j = i; j < n; j++)
        {
            if (trie[node][str[j] - 'a'] == 0)
                break;

            node = trie[node][str[j] - 'a'];

            if (stop[node])
                dp[i] = (dp[i] + dp[j + 1]) % M;
        }
    }

    cout << dp[0];
}