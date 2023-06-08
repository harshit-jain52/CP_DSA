#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n, m;
    vector<int> a(26, 0), b(26, 0);
    int i;

    cin >> n >> m;

    for (i = 0; i < n.size(); i++)
    {
        a[n[i] - 'a']++;
    }
    for (i = 0; i < m.size(); i++)
    {
        b[m[i] - 'a']++;
    }

    int area = 0;

    for (i = 0; i < 26; i++)
    {
        if (b[i] == 0)
        {
            continue;
        }
        else if (a[i] == 0)
        {
            break;
        }
        else
        {
            if (a[i] >= b[i])
            {
                area += b[i];
            }
            else
            {
                area += a[i];
            }
        }
    }

    if (i == 26)
    {
        cout << area;
    }
    else
    {
        cout << -1;
    }
}