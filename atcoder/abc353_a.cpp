#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    FASTIO
    int n;
    cin >> n;
    int h[n];
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        if (idx == -1 && h[i] > h[0])
            idx = i + 1;
    }

    cout << idx;
}