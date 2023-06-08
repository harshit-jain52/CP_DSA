#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int main()
{
    string s;
    vector<int> v(N); // 1-based indexing
    int q, i;

    cin >> s; // 0-based indexed

    for (i = 0; i < s.size() - 1; i++)
    {
        v[i + 1] = v[i];
        if (s[i] == s[i + 1])
        {
            v[i + 1]++;
        }
    }
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << v[r - 1] - v[l - 1] << endl;
    }
}