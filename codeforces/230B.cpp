#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
vector<bool> isPrime(N, 1);

void sieve()
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 0; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

bool isTprime(ll x)
{
    ll num = sqrt(x);

    if (num * num == x && isPrime[num])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    ll x[n];

    for (i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    sieve();

    for (i = 0; i < n; i++)
    {
        if (isTprime(x[i]))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}