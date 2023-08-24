#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        char letters[n][m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> letters[i][j];
            }
        }

        string name = "vika";
        int pt = 0;

        bool likeIt = false;
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (letters[i][j] == name[pt])
                {
                    pt++;
                    break;
                }
            }
            if (pt == 4)
            {
                likeIt = true;
                break;
            }
        }

        if (likeIt)
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}