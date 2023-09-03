/*
https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/xor-challenge-2420f189/*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll prod(int i, int c, int a, int b)
{
    if (i < 0)
        return a * 1LL * b;

    ll ans = 0;
    if (((1 << i) & c) != 0)
    {
        ans = max(ans, prod(i - 1, c, a | (1 << i), b));
        ans = max(ans, prod(i - 1, c, a, b | (1 << i)));
    }
    else
    {
        ans = max(ans, prod(i - 1, c, a | (1 << i), b | (1 << i)));
    }

    return ans;
}

int main()
{
    int c;
    cin >> c;

    int len = (int)log2(c) + 1;

    cout << prod(len-1,c,0,0);
}