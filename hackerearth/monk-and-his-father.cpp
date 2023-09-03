/*
https://www.hackerearth.com/problem/algorithm/monk-and-his-father-93b639f4/
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll P;
        cin >> P;

        int ct = 0;
        while (P)
        {
            ct += (P & 1);
            P >>= 1;
        }

        cout << ct << endl;
    }
}