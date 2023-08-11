#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 2e5 + 5;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> temps(N, 0);

    while (n--)
    {
        int l, r;
        cin >> l >> r;
        temps[l]++;
        temps[r + 1]--;
    }

    for (int i = 1; i < N; i++)
    {
        temps[i] += temps[i - 1];
    }

    vector<int> admis(N, 0);

    for (int i = 1; i < N; i++)
    {
        if (temps[i] >= k)
            admis[i] = 1;
        admis[i] += admis[i - 1];
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << admis[b] - admis[a - 1] << endl;
    }
}