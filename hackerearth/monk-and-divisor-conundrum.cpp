/*
https://www.hackerearth.com/problem/algorithm/monk-and-divisor-conundrum-56e0eb99/
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200001;
vector<int> divisors[N];

void generateDivisors()
{
    int i, j;
    for (i = 2; i < N; i++)
    {
        for (j = i; j < N; j += i)
        {
            divisors[j].push_back(i);
        }
    }
}

ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    int a[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    generateDivisors();
    vector<int> ct(N);
    ct[1] = n;

    for (i = 0; i < n; i++)
    {
        for (auto it : divisors[a[i]])
        {
            ct[it]++;
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        ll p, q, l;
        cin >> p >> q;
        l = lcm(p, q);

        int ans = ct[p] + ct[q];
        if (l < N)
        {
            ans -= ct[l];
        }
        cout << ans << endl;
    }
}