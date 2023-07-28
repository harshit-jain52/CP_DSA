#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        vector<int> left1(n), right0(n);

        left1[0] = (int)(s[0] == '1');
        for (int i = 1; i < n; i++)
        {
            left1[i] = left1[i - 1] + (int)(s[i] == '1');
        }

        right0[0] = (int)(s[n - 1] == '0');
        for (int i = 1; i < n; i++)
        {
            right0[i] = right0[i - 1] + (int)(s[n - 1 - i] == '0');
        }

        set<pair<int, int>> st;
        bool isSorted = false;
        while (m--)
        {
            int l, r;
            cin >> l >> r;
            l = l - 1, r = r - 1;

            if (s[l] == '0')
            {
                l = (int)(upper_bound(left1.begin() + l, left1.end(), left1[l]) - left1.begin());
            }
            if (s[r] == '1')
            {
                r = n - 1 - (int)(upper_bound(right0.begin() + n - 1 - r, right0.end(), right0[n - 1 - r]) - right0.begin());
            }

            if (l < r)
                st.insert({l, r});
            else
                isSorted = true;
        }
        cout << st.size() + (int)isSorted << endl;
    }
}