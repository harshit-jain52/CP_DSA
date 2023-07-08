#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int binExp(int a, int b, int m)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b = b >> 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (c == 0)
            cout << a;
        else if (b == 0)
            cout << 1;
        else
        {
            cout << binExp(a, binExp(b, c, M - 1), M);
        }

        cout << endl;
    }
}