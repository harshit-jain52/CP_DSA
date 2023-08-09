#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'r')
            ans.push_back(i + 1);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'l')
            ans.push_back(i + 1);
    }

    for (auto it : ans)
    {
        cout << it << endl;
    }
}