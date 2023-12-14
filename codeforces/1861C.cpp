#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

bool solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> vec(n + 2, -1);
    vec[0] = vec[1] = 1;
    int len = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+')
        {
            len++;

            if (len < 2)
                vec[len] = 1;
            else if (vec[len - 1] == 0)
                vec[len] = 0;
            else
                vec[len] = -1;
        }
        else if (s[i] == '-')
        {
            if (len == 0)
                return false;
            len--;

            if (len < 2)
                vec[len] = 1;
            else if (vec[len + 1] == 1)
                vec[len] = 1;
        }
        else
        {
            if (vec[len] == -1)
                vec[len] = s[i] - '0';
            else if (vec[len] != s[i] - '0')
                return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
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