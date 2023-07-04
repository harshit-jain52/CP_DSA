#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int xbits[31], tmpbits[31];

void decimaltobinary(int num)
{
    for (int i = 0; i < 31; i++)
    {
        tmpbits[i] = ((num >> i) & 1);
    }
}

bool cmp()
{
    for (int i = 0; i < 31; i++)
    {
        if (tmpbits[i] == 1 && xbits[i] == 0)
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
        int n, x;
        cin >> n >> x;

        for (int i = 0; i < 31; i++)
        {
            xbits[i] = ((x >> i) & 1);
        }

        int a[n], b[n], c[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }

        int numa = 0;
        for (int i = 0; i < n; i++)
        {
            decimaltobinary(numa | a[i]);
            if (cmp())
                numa |= a[i];
            else
                break;
        }

        int numb = 0;
        for (int i = 0; i < n; i++)
        {
            decimaltobinary(numb | b[i]);
            if (cmp())
                numb |= b[i];
            else
                break;
        }

        int numc = 0;
        for (int i = 0; i < n; i++)
        {
            decimaltobinary(numc | c[i]);
            if (cmp())
                numc |= c[i];
            else
                break;
        }

        int ans = (numa | numb | numc);

        if (ans == x)
            cout << "Yes";
        else
            cout << "No";

        cout << endl;
    }
}