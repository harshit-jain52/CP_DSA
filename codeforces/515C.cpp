#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ct[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    2! - 2!
    3! - 3!
    4! - 3! 2! 2!
    5! - 5!
    6! - 5! 3!
    7! - 7!
    8! - 7! 2! 2! 2!
    9! - 7! 3! 3! 2!
    */

    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        int x = (s[i] - '0');
        if (x == 2 || x == 3 || x == 5 || x == 7)
        {
            ct[x]++;
        }
        else
        {
            if (x == 4)
            {
                ct[3]++;
                ct[2] += 2;
            }
            else if (x == 6)
            {
                ct[5]++;
                ct[3]++;
            }
            else if (x == 8)
            {
                ct[7]++;
                ct[2] += 3;
            }
            else if (x == 9)
            {
                ct[7]++;
                ct[3] += 2;
                ct[2]++;
            }
        }
    }

    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < ct[i]; j++)
        {
            cout << i;
        }
    }
}
