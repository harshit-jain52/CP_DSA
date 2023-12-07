#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector<int> freq(N + 1, 0);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }

    for (int gcd = N; gcd > 0; gcd--)
    {
        int ct = 0;
        for (int j = gcd; j <= N; j += gcd)
            ct += freq[j];

        if (ct > 1)
        {
            cout << gcd;
            break;
        }
    }
}