#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m;
bool flag;

void func(int x)
{
    if (x == m)
    {
        flag = 1;
        return;
    }
    if (x < m || x % 3 != 0)
    {
        return;
    }

    func(x / 3);
    func(2 * x / 3);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        flag = 0;
        int n;
        cin >> n >> m;

        func(n);

        if (flag)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}