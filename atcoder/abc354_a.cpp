#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    FASTIO
    int h;
    cin >> h;
    int day = 0;
    while (h >= 0)
    {
        h -= (1 << day);
        day++;
    }
    cout << day << endl;
}