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
        int n, a, totalxor = 0, i;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> a;
            totalxor = totalxor ^ a;
        }
        if (n & 1)
        {
            cout << totalxor << endl;
        }
        else
        {
            if (totalxor)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        // XOR props: a^a = 0; a^0 = a; associative
    }
}