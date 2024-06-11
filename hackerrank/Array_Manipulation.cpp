#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
long long int A[N];

int main()
{
    long long n, m, a, b, k, i;
    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b >> k;

        // Hashing
        A[a] += k;
        A[b + 1] -= k;
    }

    for (i = 1; i <= n; i++)
    {
        // Prefix Sum
        A[i] = A[i] + A[i - 1];
    }

    long long max = 0;
    for (i = 1; i <= n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    cout << max;
}

// https://www.hackerrank.com/challenges/crush/problem