#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using ii = pair<int, int>;

const int N = 1e6 + 10;
vector<bool> isPrime;
vector<int> sp(N), hp(N);
vector<int> divis[N];

// Root N techniques

bool checkPrime(ll num) // O(sqrt(num))
{
    if (num < 2)
        return false;

    for (int i = 2; i * 1LL * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

vector<ll> divisors(ll num) // O(sqrt(num))
{
    vector<ll> divs;
    for (ll i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            divs.push_back(i);
            if (i != num / i)
                divs.push_back(num / i);
        }
    }

    return divs;
}

vector<ii> primeFactorization(ll num) // O(sqrt(num))
{
    vector<ii> primeFactors;
    for (ll i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            int cnt = 0;
            while (num % i == 0)
            {
                num /= i;
                cnt++;
            }
            primeFactors.push_back({i, cnt});
        }
    }

    if (num > 1)
        primeFactors.push_back({num, 1});

    return primeFactors;
}

// Sieve of Eratosthenes

// Find all prime numbers upto N, N <= 1e7
void sieve() // O(NloglogN)
{
    isPrime.assign(N, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            /*
            for (int j = 2 * i; j < N; j += i)
                isPrime[j] = false;
            */
            for (ll j = i * 1LL * i; j < N; j += i)
                isPrime[j] = false;
        }
    }
}

// Find all primes in range [L, R], 0 <= L <= R <= 1e12, R - L <= 1e6
vector<bool> segmentedSieve(ll L, ll R) // O((R - L + 1)loglog(R))
{
    // Precompute primes upto sqrt(R)
    vector<bool> is_prime(sqrt(R) + 1, true);
    vector<ll> primes;
    for (ll i = 2; i * i <= R; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j * j <= R; j += i)
                is_prime[j] = false;
        }
    }

    vector<bool> is_prime_range(R - L + 1, true);
    if (L == 1)
        is_prime_range[0] = false;

    for (ll p : primes)
    {
        ll curMul = ((L + p - 1) / p) * p; // Multiple of p >= L
        while (curMul <= R)
        {
            if (curMul != p)
                is_prime_range[curMul - L] = false;
            curMul += p;
        }
    }

    return is_prime_range;
}

// Find prime factorization of N, N <= 1e6
void highestPrimeFactor() // O(NloglogN)
{
    isPrime.assign(N, true);
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

void smallestPrimeFactor() // O(NloglogN)
{
    for (int i = 2; i < N; i++)
        sp[i] = i;

    for (int i = 2; i < N; i++)
    {
        if (sp[i] == i) // i is prime
            for (int j = 2 * i; j < N; j += i)
                sp[j] = min(sp[j], i);
    }
}

vector<int> primeFact(int num) // O(log(num))
{
    vector<int> primeFactors;
    int prime_factor;
    while (num > 1)
    {
        primeFactors.push_back(hp[num]);
        num /= hp[num];

        // primeFactors.push_back(sp[num]);
        // num /= prime_factor;
    }

    return primeFactors;
}

// Find all divisors of numbers upto N, N <= 1e6
void divisors() // O(NlogN)
{
    for (int i = 2; i < N; i++)
        for (int j = i; j < N; j += i)
            divis[j].push_back(i);
}

// Find Euler Totient Function (no. of ) of all numbers upto N, N <= 1e6
// phi(N) = no. of positive integers < N coprime with N = N * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk), where p1, p2, ..., pk are prime factors of N
vector<int> eulerTotient() // O(NloglogN)
{
    vector<int> phi(N);
    isPrime.assign(N, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 1; i < N; i++)
        phi[i] = i;

    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i; j < N; j += i)
            {
                phi[j] -= phi[j] / i;
                isPrime[j] = false;
            }
        }
    }
}
// Propoerties of Euler Totient Function
// 1. phi(p) = p - 1, where p is prime
// 2. phi(p^k) = p^k - p^(k - 1), where p is prime
// 3. phi(a * b) = phi(a) * phi(b), if gcd(a, b) = 1