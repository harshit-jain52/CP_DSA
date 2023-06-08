#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPresent(string s, char c)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
        {
            return true;
        }
    }
    return false;
}

int diff(string s)
{
    char min = '9', max = '0';
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] > max)
        {
            max = s[i];
        }
        if (s[i] < min)
        {
            min = s[i];
        }
    }
    return (max - min);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        ll l, r, i;
        string s;
        cin >> l >> r;
        if (r - l >= 99)
        {
            for (i = l; i <= r; i++)
            {
                s = to_string(i);
                if (isPresent(s, '0') && isPresent(s, '9'))
                {
                    cout << s;
                    break;
                }
            }
        }
        else if (r == l)
        {
            cout << r;
        }
        else
        {
            int arr[r - l + 1];
            for (i = 0; i < r - l + 1; i++)
            {
                arr[i] = diff(to_string(l + i));
            }

            int pos = max_element(arr, arr + r - l + 1) - arr;
            cout << l + pos;
        }
        cout << '\n';
    }
}