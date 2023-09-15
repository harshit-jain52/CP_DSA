#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 1e5 + 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> track(N, 0);

    for (int i = 1, num = 2; i < N; num++)
    {
        track[i] = 1;
        i += num;
    }

    for (int i = 1; i < N; i++)
    {
        track[i] = track[i - 1] + track[i];
    }

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << track[b] - track[a - 1] << endl;
    }
}