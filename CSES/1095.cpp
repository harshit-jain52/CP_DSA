#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int binExp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
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
        int a, b;
        cin >> a >> b;
        if (a == 0)
        {
            if (b == 0)
                cout << 1;
            else
                cout << 0;
        }
        else
            cout << binExp(a, b);

        cout << endl;
    }
}