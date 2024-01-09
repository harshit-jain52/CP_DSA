#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

vector<int> manacher(string &s)
{
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
}

int main()
{
    FASTIO
    string str;
    cin >> str;

    vector<int> p = manacher(str);
    // for (auto it : p)
    //     cout << it << " ";
    // cout << endl;
    int idx = max_element(p.begin() + 1, p.end() - 1) - p.begin();
    int len = p[idx] - 1;
    // cout << idx << " " << len << endl;

    int start = idx / 2 - len / 2;
    for (int i = start; i < start + len; i++)
    {
        cout << str[i];
    }
}