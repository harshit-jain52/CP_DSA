#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, int> hash;
    for (int i = 0; i < 31; i++)
    {
        hash[(i * (i + 1)) / 2] = i;
    }
    
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, count, i;
        cin >> n >> k;

        count = hash[k];

        for (i = 1; i <= count; i++)
        {
            cout << 1 << " ";
        }

        for (; i < n; i++)
        {
            cout << -1000 << " ";
        }
        cout << endl;
    }
}