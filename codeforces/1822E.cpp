#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(int x, int y)
{
    return (x > y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if (n % 2 == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            vector<int> swap_with(26, 0), to_swap(26, 0);
            int i, j;

            for (i = 0; i < n / 2; i++)
            {
                if (s[i] == s[n - 1 - i])
                {
                    to_swap[s[i] - 'a']++;
                }

                for (j = 0; j < 26; j++)
                {
                    if (j == s[i] - 'a' || j == s[n - 1 - i] - 'a')
                    {
                        continue;
                    }
                    swap_with[j]++;
                }
            }

            bool isPossible = true;

            for (i = 0; i < 26; i++)
            {
                isPossible &= to_swap[i] <= swap_with[i];
            }

            if (isPossible)
            {
                // cout << "yup" << endl;

                sort(to_swap.begin(), to_swap.end(),cmp);
                int sum = accumulate(to_swap.begin(), to_swap.end(), 0);

                if (to_swap[0] >= sum - to_swap[0])
                {
                    cout << to_swap[0];
                }
                else
                {
                    cout << sum / 2 + (int)(sum % 2 != 0);
                }
            }
            else
            {
                cout << -1;
            }
            cout << endl;
        }
    }
}