#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        int diff = abs(b - a);
        int num = diff / c + (int)(diff % c != 0);
        cout << num / 2 + (num % 2) << endl;
    }
}