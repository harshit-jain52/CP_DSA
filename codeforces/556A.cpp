#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, count1 = 0, count0 = 0;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case '0':
            count0++;
            break;
        case '1':
            count1++;
            break;
        }
    }

    cout << n - 2 * min(count0, count1);
}