#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e6 + 1;

int a[N], b[N];
int main()
{
    FASTIO
    a[1] = b[1] = 1;

    for (int i = 2; i < N; i++)
    {
        a[i] = ((4LL * a[i - 1]) % M + b[i - 1]) % M;
        b[i] = ((2LL * b[i - 1]) % M + a[i - 1]) % M;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (a[n] + b[n]) % M << endl;
    }
}