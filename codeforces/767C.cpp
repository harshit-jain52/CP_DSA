#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
vector<int> tree[N];
int temp[N];
int parent[N];
int v_sum[N];

void dfs(int vertex)
{
    v_sum[vertex] += temp[vertex];

    for (auto child : tree[vertex])
    {
        dfs(child);
        v_sum[vertex] += v_sum[child];
    }
}

void revdfs(int child, int diff)
{
    if (parent[child] == 0)
    {
        return;
    }
    v_sum[parent[child]] -= diff;
    revdfs(parent[child], diff);
}

void lowestCut(int vertex, int val, int &cut)
{
    if (v_sum[vertex] == val)
    {
        cut = vertex;
    }

    for (auto child : tree[vertex])
    {
        lowestCut(child, val, cut);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, root;
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        int a, t;
        cin >> a >> t;

        parent[i] = a;
        if (a == 0)
        {
            root = i;
        }
        else
        {
            tree[a].push_back(i);
        }

        temp[i] = t;
    }

    dfs(root);

    // for (i = 1; i <= n; i++)
    // {
    //     cout << v_sum[i] << " ";
    // }

    int total = v_sum[root];

    if (total % 3 != 0)
    {
        cout << -1;
    }
    else
    {
        int cut1 = 0, cut2 = 0;

        for (i = 1; i <= n; i++)
        {
            if (i == root)
                continue;

            if (v_sum[i] == total / 3)
            {
                cut1 = i;
                break;
            }
        }

        if (cut1 > 0)
        {
            lowestCut(cut1, total / 3, cut1);
            revdfs(cut1, total / 3);

            for (i = 1; i <= n; i++)
            {
                if (i == cut1 || i == root)
                    continue;

                if (v_sum[i] == total / 3)
                {
                    cut2 = i;
                    break;
                }
            }
            if (cut2 > 0)
            {
                cout << cut1 << " " << cut2;
            }
            else
            {
                cout << -1;
            }
        }
        else
        {
            cout << -1;
        }
    }
}