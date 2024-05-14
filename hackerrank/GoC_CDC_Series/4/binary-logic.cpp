#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int rem = 0;

    for (int i = 0; i < n; i++)
    {
        rem = ((rem * 2) % k + (s[i] == '1')) % k;
    }
    cout << ((rem == 0) ? "Yes" : "No");
}