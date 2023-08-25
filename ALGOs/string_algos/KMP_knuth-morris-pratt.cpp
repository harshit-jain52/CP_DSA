#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s)
{
    /*
    The prefix function for this string is defined as an array pi of length n,
    where  pi[i]  is the length of the longest proper prefix of the substring s[0 ... i] which is also a suffix of this substring.
    */

    int n = s.length();
    vector<int> pi(n);
    pi[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int l = pi[i - 1];

        while (l > 0 && s[i] != s[l])
            l = pi[l - 1];

        if (s[i] == s[l])
            l++;

        pi[i] = l;
    }

    return pi;

    // O(N)
}

int main()
{
}