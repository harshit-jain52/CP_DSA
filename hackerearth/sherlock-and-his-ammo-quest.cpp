/*
https://www.hackerearth.com/problem/algorithm/stl/
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<string, int> a, pair<string, int> b)
{
    if (a.second != b.second)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, i;
    cin >> N;
    vector<pair<string, int>> v(N);

    for (i = 0; i < N; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    for (i = 0; i < N; i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
}