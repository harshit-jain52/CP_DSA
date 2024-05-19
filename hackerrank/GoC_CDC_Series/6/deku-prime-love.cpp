#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2;
typedef long long ll;

vector<bool> segmentSieve(int L, int R)
{
    vector<bool> isprime(sqrt(R) + 1, true);
    vector<ll> primes;

    for (ll i = 2; i * i <= R; i++)
    {
        if (isprime[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j * j <= R; j += i)
                isprime[j] = false;
        }
    }

    vector<bool> isPrimeRange(R - L + 1, true);
    if (L == 1)
        isPrimeRange[0] = false;

    for (ll p : primes)
    {
        ll curMul = ((L + p - 1) / p) * 1LL * p;
        while (curMul <= R)
        {
            if (curMul != p)
                isPrimeRange[curMul - L] = false;
            curMul += p;
        }
    }

    return isPrimeRange;
}

int main()
{
    int n;
    cin >> n;
    ll a[n], L = INT_MAX, R = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        L = min(L, a[i]);
        R = max(R, a[i]);
    }

    vector<bool> isPrime = segmentSieve(L, R);
    int tail = 0, head = -1;

    int maxlen = 0;
    while (tail < n)
    {
        while (head + 1 < n && isPrime[a[head + 1] - L])
            head++;
        maxlen = max(maxlen, head - tail + 1);

        if (head >= tail)
            tail++;
        else
        {
            tail++;
            head = tail - 1;
        }
    }
    cout << maxlen;
}