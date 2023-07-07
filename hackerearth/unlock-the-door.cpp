/*
https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/name-count/
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int M = 1e9 + 7;
const int N = 1e5 + 1;
int fact[N];

// ans = (kCn)*n! = k!/(k-n)!

int binExp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b = b >> 1;
    }
    return ans;
}

int main()
{
    fact[0] = fact[1] = 1;

    for (int i = 2; i < N; i++)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % M;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << (fact[k] * 1LL * binExp(fact[k - n], M - 2)) % M << endl;
    }
}