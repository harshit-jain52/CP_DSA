#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 2e5 + 5;
vector<int> t[N];
int sub[N];

void dfs(int boss)
{
    for (auto child : t[boss])
    {
        dfs(child);
        sub[boss] += (1 + sub[child]);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int boss;
        cin >> boss;
        t[boss].push_back(i);
    }
    dfs(1);

    for (int i = 1; i <= n; i++)
    {
        cout << sub[i] << " ";
    }
}