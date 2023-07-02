#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    vector<bool> a(n + 1, false);
    for (int i = 0; i < n - 1; i++)
    {
        int tmp;
        cin >> tmp;
        a[tmp] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == false)
        {
            cout << i;
            break;
        }
    }
}