#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
vector<bool> isPrime(N, 1);

void sieve()
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < N; i++)
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    int a[n + 2];
    int flag = 0;

    sieve();

    for (i = 2; i < n + 2; i++)
    {
        if (isPrime[i])
        {
            a[i] = 1;
        }
        else
        {
            flag = 1;
            a[i] = 2;
        }
    }

    cout << flag + 1 << endl;
    for (i = 2; i < n + 2; i++)
    {
        cout << a[i] << " ";
    }
}