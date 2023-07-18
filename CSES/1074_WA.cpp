#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll p[n], tot = 0, avg;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        tot += p[i];
    }
    avg = tot / n;

    ll tmpcost1 = 0, tmpcost2 = 0;

    for (int i = 0; i < n; i++)
    {
        tmpcost1 += abs(p[i] - avg);
        tmpcost2 += abs(p[i] - (avg + 1));
    }

    cout << min(tmpcost1, tmpcost2);
}