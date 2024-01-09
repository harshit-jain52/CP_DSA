#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string &s) // TC: O(N^2)
{
    int n = s.size();
    int lo, hi, mid, len;

    int maxlen = 1, ipos = 0;
    for (mid = 0; mid < n; mid++)
    {

        // even
        lo = mid - 1;
        hi = mid;
        while (lo >= 0 && hi < n && s[lo] == s[hi])
        {
            len = hi - lo + 1;
            if (len > maxlen)
            {
                maxlen = len;
                ipos = lo;
            }
            lo--;
            hi++;
        }

        // odd
        lo = mid - 1;
        hi = mid + 1;
        while (lo >= 0 && hi < n && s[lo] == s[hi])
        {
            len = hi - lo + 1;
            if (len > maxlen)
            {
                maxlen = len;
                ipos = lo;
            }
            lo--;
            hi++;
        }
    }

    string ans = "";
    for (int l = 0; l < maxlen; l++)
    {
        ans.push_back(s[ipos++]);
    }

    return ans;
}