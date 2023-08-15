#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

vector<int> kmp(vector<int> &v)
{
    int n = v.size();
    vector<int> pi(n);
    pi[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int l = pi[i - 1];

        while (l > 0 && v[i] != v[l])
            l = pi[l - 1];

        if (v[i] == v[l])
            l++;

        pi[i] = l;
    }

    return pi;
}

int main()
{
    int n, w;
    cin >> n >> w;

    int b[n], e[w];

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < w; i++)
    {
        cin >> e[i];
    }

    if (w > n)
        cout << 0;
    else if (w == 1)
        cout << n;
    else
    {
        vector<int> diff;

        for (int i = 1; i < w; i++)
        {
            diff.push_back(e[i] - e[i - 1]);
        }

        diff.push_back(1e9); // wall

        for (int i = 1; i < n; i++)
        {
            diff.push_back(b[i] - b[i - 1]);
        }

        vector<int> v = kmp(diff);

        int ct = 0;

        for (int i = w; i <= w + n - 2; i++)
        {
            if (v[i] == w-1)
                ct++;
        }

        cout << ct;
    }
}