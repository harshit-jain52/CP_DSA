#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;

        if (k == x && k == 1)
        {
            cout << "NO";
        }
        else
        {
            int lowest, rem = n;

            for (int i = 1; i <= k; i++)
            {
                if (i != x)
                {
                    lowest = i;
                    break;
                }
            }

            int ct = 0;
            vector<int> to_print;
            bool ans = false;
            while (rem > 0)
            {
                ct++;
                if (rem <= k && rem != x)
                {
                    to_print.push_back(rem);
                    ans = true;
                    break;
                }
                rem -= lowest;
                to_print.push_back(lowest);
            }

            if (ans)
            {
                cout << "YES" << endl
                     << ct << endl;

                for (auto it : to_print)
                {
                    cout << it << " ";
                }
            }
            else
            {
                cout << "NO";
            }
        }
        cout << endl;
    }
}