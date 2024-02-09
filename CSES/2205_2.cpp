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

    int lim = (1 << n);
    for (int i = 0; i < lim; i++)
    {
        int num = i ^ (i >> 1);
        for (int j = n - 1; j >= 0; j--)
        {
            cout << (((1 << j) & num) != 0);
        }
        cout << endl;
    }
}