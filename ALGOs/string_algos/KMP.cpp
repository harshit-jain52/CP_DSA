#include <bits/stdc++.h>
using namespace std;

// KMP - Knuth-Morris-Pratt
/*
    The prefix function for this string is defined as an array lps of length n,
    where  lps[i]  is the length of the longest proper prefix of the substring s[0 ... i] which is also a suffix of this substring.
*/
// O(N)

vector<int> prefix_function(string s)
{
    int n = s.length();
    vector<int> lps(n + 1);

    int i = 0, j = -1;
    lps[0] = -1;

    while (i < n)
    {
        while (j != -1 && s[j] != s[i]) // try to find previous match
            j = lps[j];
        i++;
        j++;
        lps[i] = j;
    }

    return lps; // 1-indexed
}