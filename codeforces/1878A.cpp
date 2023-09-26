#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        bool ans = false;

        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == k)
                ans = true;
        }

        if (ans)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}