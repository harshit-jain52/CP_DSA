#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1, maxtmp = 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            maxtmp++;
        else
            maxtmp = 1;

        ans = max(ans, maxtmp);
    }

    cout << ans;
}