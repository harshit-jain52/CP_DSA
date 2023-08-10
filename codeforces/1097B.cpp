#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool func(int a[], int idx, int sum)
{
    if (idx < 0)
        return sum%360 == 0;

    bool ans = false;

    ans |= func(a, idx - 1, sum - a[idx]);
    ans |= func(a, idx - 1, sum + a[idx]);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (func(a, n - 1, 0))
        cout << "YES";
    else
        cout << "NO";
}