#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
    int n, b, c;
    cin >> n >> b >> c;

    int x = (b ^ c);
    if (x > n || x > (min(b, n - c) + min(c, n - b)) || x < max(b, c) - min(b, c))
    {
        cout << "NO";
        return;
    }

    vector<char> v1(n);
    vector<char> v2(n);
    int i, k;
    if (b <= c)
    {
        k = c;
        i = 0;
        while (k > b)
        {
            v2[i] = '1';
            v1[i] = '0';
            i++;
            k--;
        }
    }
    else
    {
        k = b;
        i = 0;
        while (k > c)
        {
            v2[i] = '0';
            v1[i] = '1';
            i++;
            k--;
        }
    }
    int storei = i;
    int left = x - i;

    if (left % 2 == 1)
    {
        cout << "NO";
        return;
    }

    while (left > 0)
    {
        if (i % 2 == 0)
        {
            v1[i] = '1';
            v2[i] = '0';
        }
        else
        {
            v2[i] = '1';
            v1[i] = '0';
        }
        i++;
        left--;
    }

    int j = i;
    k -= (j - storei) / 2;

    while (k > 0)
    {
        v1[i] = '1';
        v2[i] = '1';
        i++;
        k--;
    }

    while (i < n)
    {
        v1[i] = '0';
        v2[i] = '0';
        i++;
    }

    cout << "YES" << endl;
    for (auto c : v1)
        cout << c;
    cout << endl;
    for (auto c : v2)
        cout << c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}