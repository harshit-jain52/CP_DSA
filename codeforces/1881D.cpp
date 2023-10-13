#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
vector<bool> isPrime(N, 1);
vector<int> hp(N, 0);

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

vector<int> primeFactorization(int num)
{
    vector<int> primeFactors;
    int prime_factor;
    while (num > 1)
    {
        prime_factor = hp[num];
        while (num % prime_factor == 0)
        {
            num /= prime_factor;
            primeFactors.push_back(prime_factor);
        }
    }

    return primeFactors;
}

bool solve()
{
    int n;
    cin >> n;
    ll a[n];
    ll p = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    map<int, int> m;
    vector<int> tmp;
    for (int i = 0; i < n; i++)
    {
        tmp = primeFactorization(a[i]);
        for (auto it : tmp)
        {
            m[it]++;
        }
    }

    for (auto it : m)
    {
        if (it.second % n != 0)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    highestPrimeFactor();
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}