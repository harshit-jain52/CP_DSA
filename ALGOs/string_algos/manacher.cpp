#include <bits/stdc++.h>
using namespace std;

vector<int> manacher(string &s)
{

    // Make every palindrome odd-centered
    string t = "#";
    for (char c : s)
    {
        t.push_back(c);
        t.push_back('#');
    }

    int n = t.size();
    vector<int> p(n, 1);
    int l = 1, r = 1;
    for (int i = 1; i < n; i++)
    {
        p[i] = max(1, min(r - i, p[l + r - i]));
        while (i + p[i] < n && i - p[i] >= 0 && t[i + p[i]] == t[i - p[i]])
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