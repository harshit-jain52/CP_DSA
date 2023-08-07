#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin >> x;

        int here9 = -1;
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] >= '5')
            {
                here9 = i;
                break;
            }
        }
        for (int i = here9 - 1; i >= 0; i--)
        {
            if (x[i] != '4')
                break;
            here9 = i;
        }

        if (here9 != -1)
        {
            if (here9 == 0)
            {
                for (int i = here9; i < x.size(); i++)
                {
                    x[i] = '0';
                }
                x = "1" + x;
            }
            else
            {
                x[here9 - 1] = x[here9 - 1] + 1;
                for (int i = here9; i < x.size(); i++)
                {
                    x[i] = '0';
                }
            }
        }
        cout << x << endl;
    }
}