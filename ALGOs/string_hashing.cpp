/*
https://cp-algorithms.com/string/string-hashing.html
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int p = 31;
const int M = 1e9 + 9;

ll coumpute_hash(string &s)
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