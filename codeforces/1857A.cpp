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
        int oddct = 0, evenct = 0;

        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;

            if (tmp % 2 == 0)
                evenct++;
            else
                oddct++;
        }

        if (oddct % 2 == 0)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}