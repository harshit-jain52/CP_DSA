#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        int ct = 0, num = 1;
        while (1)
        {
            if (n % num != 0)
            {
                ct = num - 1;
                break;
            }
            num++;
        }
        cout << ct << endl;
    }
}