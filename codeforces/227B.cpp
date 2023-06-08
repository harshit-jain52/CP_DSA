#include <bits/stdc++.h>
using namespace std;
int index[100001];
int main()
{
    int n;
    cin >> n;
    int a[n], i;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        index[a[i]] = i;
    }

    int m, temp;
    long long vasya = 0, pretya = 0;
    cin >> m;

    for (i = 0; i < m; i++)
    {
        cin >> temp;

        vasya += index[temp] + 1;
        pretya += n - index[temp];
    }

    cout << vasya << " " << pretya;
}