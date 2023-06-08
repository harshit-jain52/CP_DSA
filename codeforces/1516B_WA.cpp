#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        cin >> n;
        int x = 0;
        map<int, int> ct;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            ct[a]++;
            x = x ^ a;
        }
        bool ans = false;
        for (auto it : ct)
        {
            int elem = it.first;
            int count = it.second;
            int rem;
            if (count % 2 == 1)
            {
                rem = x ^ elem;
                if (rem == elem || (rem == 0 && count > 1))
                {
                    ans = true;
                    break;
                }
            }
            else
            {
                if (x == 0)
                {
                    ans = true;
                    break;
                }
            }
        }

        if (ans)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }
}