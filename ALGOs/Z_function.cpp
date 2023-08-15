#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s)
{
    /*
    The Z-function for this string is an array of length n where the i-th element is equal to the greatest number of characters
    starting from the position i that coincide with the first characters of s.
    z[i] is the length of the longest string that is, at the same time, a prefix of s and a prefix of the suffix of s starting at i.
    */

    int n = s.length();
    vector<int> z(n, 0);

    int l = 0, r = 0;

    // [l,r) indices of the rightmost segment match (substring coinciding with prefix of s)

    for (int i = 1; i < n; i++)
    {
        if (i < r)
            z[i] = min(r - i, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }

    return z;

    // O(N)
}

int main()
{
}