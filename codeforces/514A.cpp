#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string x;
    cin >> x;

    for (int i = 0; i < x.size(); i++)
    {
        if (i == 0 && x[i] == '9')
        {
            cout << x[i];
            continue;
        }

        cout << min(x[i], (char)('0' + ('9' - x[i])));
    }
}