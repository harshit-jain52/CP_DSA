#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<bool> isPrime(N, 1);
vector<int> lp(N, 0), hp(N, 0);
vector<int> divis[N];

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

    // time complexity = O(NloglogN)
}

void lowesthighestPrimeFactor()
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            lp[i] = hp[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                hp[j] = i;
                if (lp[j] == 0)
                {
                    lp[j] = i;
                }
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

void divisors()
{
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            divis[j].push_back(i);
        }
    }

    // time complexity = O(NlogN)
}

int main()
{
}