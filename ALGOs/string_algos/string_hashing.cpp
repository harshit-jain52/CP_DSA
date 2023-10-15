#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int p = 31;
const int M = 1e9 + 9;

ll compute_hash(string &s) // https://cp-algorithms.com/string/string-hashing.html
{
    ll hash_value = 0;
    ll p_pow = 1;

    for (char c : s)
    {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % M;
        p_pow = (p_pow * p) % M;
    }

    return hash_value;
}

ll hashStr(string &s) // Horner's Method
{
    ll hash_value = 0;
    for (char c : s)
    {
        hash_value = (hash_value * p + (c - 'a' + 1)) % M;
    }

    return hash_value;
}