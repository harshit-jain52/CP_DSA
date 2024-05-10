#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n;
    int a[n + 1], maxreach[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxreach[i] = min(n, i + a[i]);
        if (i > 1)
            maxreach[i] = max(maxreach[i], maxreach[i - 1]);
    }
    int currReach = 1, moves = 0;
    vector<int> mark(n + 1, 0);
    while (currReach != n)
    {
        currReach = maxreach[currReach];
        moves++;
        mark[currReach] = moves;
    }
    for (int i = n - 1; i >= 2; i--)
        if (mark[i] == 0)
            mark[i] = mark[i + 1];

    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << mark[x] << endl;
    }
}