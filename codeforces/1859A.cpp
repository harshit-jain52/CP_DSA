#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a, a + n);

        if (a[0] == a[n - 1])
            cout << -1;
        else
        {
            vector<int> b, c;

            for (int i = 0; i < n; i++)
            {
                if (a[i] == a[0])
                    b.push_back(a[i]);
                else
                    c.push_back(a[i]);
            }

            cout << b.size() << " " << c.size() << endl;
            for (auto it : b)
                cout << it << " ";
            cout << endl;
            for (auto it : c)
                cout << it << " ";
        }
        cout << endl;
    }
}