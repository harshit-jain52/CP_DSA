#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    int a[2 * n];

    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }

    for (int j = 0; j < k; j++)
    {
        cout << a[n - j - 1] << " ";
    }

    for (int j = 0; j < n - k; j++)
    {
        cout << a[j] << " ";
    }
}