#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b, c, i, j;
    cin >> n >> a >> b >> c;
    vector<int> pieces;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if ((n - i * a - j * b) < 0)
            {
                break;
            }

            if ((n - i * a - j * b) % c == 0)
            {
                pieces.push_back(i + j + (n - i * a - j * b) / c);
            }
        }
    }

    cout << *max_element(pieces.begin(), pieces.end());
}