#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int ALLSET = (1LL << 31) - 1;
vector<vector<int>> trie(1, vector<int>(2));

void insert(int num)
{
    int node = 0;
    for (int i = 30; i >= 0; i--)
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

int findMax(int num)
{
    int res = 0, node = 0;
    int find = ALLSET ^ num;
    for (int i = 30; i >= 0; i--)
    {
        int bit = (find >> i) & 1;
        if (trie[node][bit])
        {
            res += (1 << i);
            node = trie[node][bit];
        }
        else
            node = trie[node][1 ^ bit];
    }
    return res;
}

int main()
{
    FASTIO
    int ans = 0, prefxor = 0, n;
    insert(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        prefxor ^= a;
        ans = max(ans, findMax(prefxor));
        insert(prefxor);
    }
    cout << ans;
}