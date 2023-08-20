#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int p = 31;
const int M = 1e9 + 7;

bool robin_karp(string &str, string &text) // occurence of str in text
{
    int S = str.size(), T = text.size();

    if (S > T)
        return false;

    vector<ll> p_pow(T);
    p_pow[0] = 1;

    for (int i = 1; i < p_pow.size(); i++)
    {
        p_pow[i] = (p_pow[i - 1] * p) % M;
    }

    // hash values of all prefixes of text
    vector<ll> h_T(T + 1, 0);
    for (int i = 0; i < T; i++)
        h_T[i + 1] = (h_T[i - 1] + (text[i] - 'a' + 1) * p_pow[i]) % M;

    // hash value of str
    long long h_S = 0;
    for (int i = 0; i < S; i++)
        h_S = (h_S + (str[i] - 'a' + 1) * p_pow[i]) % M;

    long long cur_h;
    for (int i = 0; i + S - 1 < T; i++)
    {
        cur_h = (h_T[i + S] + M - h_T[i]) % M; // +M to avoid negative
        if (cur_h == (h_S * p_pow[i]) % M)
            return true;
    }

    return false;
}