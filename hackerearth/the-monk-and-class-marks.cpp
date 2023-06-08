/*
https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, marks, i;
    string s;
    cin >> n;
    map<int, multiset<string>> m;

    for (i = 0; i < n; i++)
    {
        cin >> s >> marks;
        m[100 - marks].insert(s);
    }

    for (auto &it : m)
    {
        for (auto &j : it.second)
        {
            cout << j << " " << 100 - it.first << endl;
        }
    }
}