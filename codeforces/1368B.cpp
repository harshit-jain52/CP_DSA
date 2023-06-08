#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "codeforces";
    ll k, prod = 1;
    cin >> k;
    vector<int> ct(10, 1);

    int i = 0;
    while (prod < k)
    {
        if (i == 10)
        {
            i = 0;
        }

        prod /= ct[i];
        ct[i]++;
        prod *= ct[i];

        i++;
    }

    for (i = 0; i < 10; i++)
    {
        for (int j = 0; j < ct[i]; j++)
        {
            cout << s[i];
        }
    }
}