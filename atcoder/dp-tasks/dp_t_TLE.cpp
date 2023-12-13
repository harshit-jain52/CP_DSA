#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int N;
string s;
int dp[3001][3001];

vector<bool> taken(3001, false);

int func(int idx, int prevnum)
{
    if (idx >= N)
        return 1;

    if (dp[idx][prevnum] != -1)
        return dp[idx][prevnum];

    int ct = 0;
    taken[prevnum] = true;

    if (s[idx - 1] == '<')
    {
        for (int i = prevnum + 1; i <= N; i++)
        {
            if (!taken[i])
                ct = (ct + func(idx + 1, i)) % M;
        }
    }
    else
    {
        for (int i = 1; i < prevnum; i++)
        {
            if (!taken[i])
                ct = (ct + func(idx + 1, i)) % M;
        }
    }
    taken[prevnum] = false;

    return dp[idx][prevnum] = ct;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> N;
    cin >> s;

    int tot = 0;
    for (int i = 1; i <= N; i++)
    {
        tot = (tot + func(1, i)) % M;
    }

    cout << tot;
}