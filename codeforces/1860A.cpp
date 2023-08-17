#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

bool isThat(string &str)
{
    int n = str.size();

    for (int i = 1; i < n; i++)
    {
        if (str[i] == str[i - 1])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();

        if (n == 2 && s=="()")
        {
            cout << "NO";
        }
        else
        {
            cout << "YES" << endl;

            if (isThat(s))
            {
                for (int i = 0; i < n; i++)
                    cout << "(";
                for (int i = 0; i < n; i++)
                {
                    cout << ")";
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    cout << "()";
                }
            }
        }

        cout << endl;
    }
}