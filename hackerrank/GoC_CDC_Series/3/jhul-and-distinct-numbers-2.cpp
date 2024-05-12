#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    set<int> a, b;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.insert(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        b.insert(tmp);
    }
    for (int num : a)
        mp[num]++;
    for (int num : b)
        mp[num]++;

    vector<int> vec;
    for (auto it : mp)
    {
        if (it.second > 1)
            continue;
        vec.push_back(it.first);
    }
    for (auto v : vec)
        cout << v << " ";
}