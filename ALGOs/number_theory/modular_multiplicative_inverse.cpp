#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7; // prime

/*
MMI of a exists only when a & M are coprime, i.e., gcd(a,M) = 1

--when M is prime--
a^(M-1) % M = 1 [Fermat's Little Theorem]
a^(M-2) % M = a^(-1)

find by binary exponentiation
TC: log(M)

--when M is not prime--
Extended Euclid Algorithm
*/

int binExp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * 1LL * a) % M;

        a = (a * 1LL * a) % M;
        b = b >> 1;
    }
    return ans;
}

int main()
{
    int a;
    int a_inv = binExp(a, M - 2);
}