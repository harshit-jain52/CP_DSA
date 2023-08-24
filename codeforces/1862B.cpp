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
        int n;
        cin >> n;
        int b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        vector<int> output;
        output.push_back(b[0]);

        for (int i = 1; i < n; i++)
        {
            if (b[i] < b[i - 1])
                output.push_back(b[i]);
            output.push_back(b[i]);
        }

        cout << output.size() << endl;

        for (auto it : output)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}