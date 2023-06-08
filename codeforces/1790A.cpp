#include <bits/stdc++.h>
using namespace std;

int main()
{
    string pi = "314159265358979323846264338327", s;
    int i, t;

    cin >> t;

    while (t--)
    {
        cin >> s;

        for (i = 0; i < s.size(); i++)
        {
            if (s[i] != pi[i])
                break;
        }

        cout << i << endl;
    }
}