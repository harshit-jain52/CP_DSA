#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        string s = "1";
        bool dec = false;
        int first;
        cin >> first;
        int prev = first;

        for (int i = 1; i < q; i++)
        {
            int x;
            cin >> x;
            if (!dec)
            {
                if (x >= prev)
                {
                    s.push_back('1');
                    prev = x;
                }
                else
                {
                    if (x <= first)
                    {
                        s.push_back('1');
                        dec = true;
                        prev = x;
                    }
                    else
                    {
                        s.push_back('0');
                    }
                }
            }
            else
            {
                if (x >= prev && x <= first)
                {
                    s.push_back('1');
                    prev = x;
                }
                else
                {
                    s.push_back('0');
                }
            }
        }
        cout << s << endl;
    }
}