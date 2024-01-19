#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

bool solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int prefxor[n], suffxor[n];
    prefxor[0] = a[0];
    suffxor[n - 1] = a[n - 1];

    for (int i = 1; i < n; i++)
    {
        prefxor[i] = prefxor[i - 1] ^ a[i];
        suffxor[n - 1 - i] = suffxor[n - i] ^ a[n - 1 - i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (j - i == 1)
            {
                if (prefxor[i] == suffxor[j])
                    return true;
            }
            else
            {
                int leftxor = prefxor[i], rightxor = suffxor[j];
                int midxor = prefxor[j - 1] ^ prefxor[i];
                if (leftxor == rightxor && leftxor == midxor)
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while (t--)
    {
        if (solve())
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}