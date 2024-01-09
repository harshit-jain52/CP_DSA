#include <bits/stdc++.h>
using namespace std;

vector<int> manacher(string &s)
{
    int n = s.size();

    // Make every palindrome odd-centered
    string t = "#";
    for (char c : s)
    {
        t.push_back(c);
        t.push_back('#');
    }

    vector<int> p(2 * n + 1, 1);
    int l = 1, r = 1;
    for (int i = 1; i < n; i++)
    {
        p[i] = max(1, min(r - i, p[l + r - i]));
        while (i + p[i] < n && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
            p[i]++;

        if (i + p[i] > r)
        {
            l = i - p[i];
            r = i + p[i];
        }
    }

    return p;
    // O(N)
}