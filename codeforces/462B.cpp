#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, i, j, count = 0;
    string s;

    vector<int> freq(26);
    vector<long long> chosen;

    cin >> n >> k;
    cin >> s;

    for (i = 0; i < n; i++)
    {
        freq[s[i] - 'A']++;
    }

    sort(freq.begin(), freq.end(), greater<int>());

    for (i = 0; i < freq.size() && count < k; i++)
    {
        for (j = 0; j < freq[i] && count < k; j++)
        {
            count++;
        }
        chosen.push_back(j);
    }

    long long coins = 0;
    for (auto it : chosen)
    {
        coins += it * it;
    }
    cout << coins;
}