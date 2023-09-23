#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    vector<pair<int, int>> time;
    int room[n + 1], ct = 0;

    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        time.push_back({a, -i});
        time.push_back({b, i});
    }

    sort(time.begin(), time.end());

    vector<int> available;
    for (auto t : time)
    {
        if (t.second > 0)
            available.push_back(room[t.second]);
        else
        {
            if (available.empty())
            {
                ct++;
                room[-t.second] = ct;
            }
            else
            {
                room[-t.second] = available[0];
                available.erase(available.begin());
            }
        }
    }

    cout << ct << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << room[i] << " ";
    }
}