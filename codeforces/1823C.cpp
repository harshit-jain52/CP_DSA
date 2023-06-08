#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);
vector<int> hp(N, 0);
unordered_map<int, int> ct;

void highestPrimeFactor()
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            hp[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                hp[j] = i;
            }
        }
    }
}

void primeFactorization(int num)
{

    int prime_factor;
    while (num > 1)
    {
        prime_factor = hp[num];
        while (num % prime_factor == 0)
        {
            ct[prime_factor]++;
            num /= prime_factor;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    highestPrimeFactor();
    int t;
    cin >> t;
    while (t--)
    {
        ct.clear();
        int n;
        cin >> n;
        ll a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            primeFactorization(a[i]);
        }

        ll rem = 0, count = 0;

        for (auto it : ct)
        {
            count += it.second / 2;
            rem += it.second % 2;
        }
        count += rem / 3;

        cout << count << endl;
    }
}