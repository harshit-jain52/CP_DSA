#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 2e5 + 5;
const int LOG = 20;

vector<int> tree[N];
int in[N], out[N], depth[N];
vector<int> euler;
int ct = 0;

void dfs(int a, int dd)
{
    in[a] = ct++;
    euler.push_back(a);
    depth[a] = dd;
    for (int b : tree[a])
    {
        dfs(b, dd + 1);
        out[a] = ct++;
        euler.push_back(a);
    }
}

int main()
{
    FASTIO

    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        int e;
        cin >> e;
        tree[e].push_back(i);
    }

    int root = 1;
    dfs(root, 0);

    int sz = euler.size();
    int binLog[sz + 1];

    // for(int i=0;i<sz; i++) cout << euler[i]<<" "<<depth[euler[i]]<<endl;

    binLog[1] = 0;
    for (int i = 2; i <= sz; i++)
        binLog[i] = 1 + binLog[i / 2];

    pair<int, int> m[sz][binLog[sz] + 1];
    for (int i = 0; i < sz; i++)
        m[i][0] = {depth[euler[i]], euler[i]};

    for (int j = 1; j <= binLog[sz]; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < sz; i++)
        {
            m[i][j] = min(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int L = in[a], R = in[b];
        if (L > R)
            swap(L, R);

        int k = binLog[R - L + 1];
        auto pp = min(m[L][k], m[R - (1 << k) + 1][k]);
        cout << pp.second << endl;
    }
}