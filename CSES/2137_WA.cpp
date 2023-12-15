#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 64;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    // dividing into N-sized blocks
    vector<vector<ll>> blocks(n);
    for (int i = 0; i < n; i++)
    {
        ll num = 0;
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                num += (1LL << (j % N));
            }
            if (j % N == N - 1 || j == n - 1)
            {
                blocks[i].push_back(num);
                num = 0;
            }
        }
    }

    int sz = blocks[0].size();
    
    ll subgrids = 0;
    for (int a = 0; a < n; a++)
    {
        for (int b = a + 1; b < n; b++)
        {
            ll ct = 0;

            for (int i = 0; i < sz; i++)
                ct += __builtin_popcount(blocks[a][i] & blocks[b][i]);

            subgrids += ct * (ct - 1) / 2;
        }
    }
    cout << subgrids;
}