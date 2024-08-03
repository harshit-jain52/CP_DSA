#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

void radix_sort(vector<pair<pair<int, int>, int>> &arr)
{
    for (int i : vector<int>{2, 1})
    {
        auto key = [&](const pair<pair<int, int>, int> &x)
        {
            return i == 1 ? x.first.first : x.first.second;
        };

        int mx = 0;
        for (const auto &i : arr)
        {
            mx = max(mx, key(i));
        }

        vector<int> occs(mx + 1);
        for (const auto &i : arr)
        {
            occs[key(i)]++;
        }

        vector<int> start(mx + 1);
        for (int i = 1; i <= mx; i++)
            start[i] = start[i - 1] + occs[i - 1];

        vector<pair<pair<int, int>, int>> new_arr(arr.size());
        for (const auto &i : arr)
        {
            new_arr[start[key(i)]] = i;
            start[key(i)]++;
        }
        arr = new_arr;
    }
}

int main()
{
    FASTIO
    string str;
    cin >> str;
    str += '$';
    const int n = str.size();

    vector<pair<pair<int, int>, int>> suffs(n);
    for (int i = 0; i < n; i++)
        suffs[i] = {{str[i], str[i]}, i};

    sort(suffs.begin(), suffs.end());
    vector<int> equiv(n);

    for (int i = 1; i < n; i++)
    {
        auto [c_val, cs] = suffs[i];
        auto [p_val, ps] = suffs[i - 1];
        equiv[cs] = equiv[ps] + (c_val > p_val);
    }

    for (int cmp_amt = 1; cmp_amt < n; cmp_amt *= 2)
    {
        for (auto &[val, s] : suffs)
            val = {equiv[s], equiv[(s + cmp_amt) % n]};

        radix_sort(suffs);
        for (int i = 1; i < n; i++)
        {
            auto [c_val, cs] = suffs[i];
            auto [p_val, ps] = suffs[i - 1];
            equiv[cs] = equiv[ps] + (c_val > p_val);
        }
    }

    int start = suffs[1].second;
    for (int i = start - 1; i >= 0; i--)
    {
        if (str[i] == str[start])
            start = i;
        else
            break;
    }

    string output;
    for (int i = start; i < n - 1; i++)
        output += str[i];
    for (int i = 0; i < start; i++)
        output += str[i];
    cout << output;
}
