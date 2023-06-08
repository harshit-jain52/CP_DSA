/*
https://www.hackerearth.com/problem/algorithm/monks-birthday-party/
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        set<string> s;
        string t;

        for (i = 0; i < n; i++)
        {
            cin >> t;
            s.insert(t);
        }
        for (auto it : s)
        {
            cout << it << endl;
        }
    }
}