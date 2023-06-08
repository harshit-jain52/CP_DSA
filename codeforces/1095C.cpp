#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    int k;
    cin >> n >> k;
    vector<ll> v;
    int i = 0;
    while (1 << i <= n)
    {
        if ((1 << i) & n)
            v.push_back((1 << i));

        i++;
    }

    if (v.size() > k || k > n)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << endl;
        int ct = v.size();
        for (int i = 0; i < v.size(); i++)
        {
            if (ct == k)
                break;
            if (v[i] == 1)
                continue;

            v.push_back(v[i] / 2);
            v.push_back(v[i] / 2);
            v[i] = 0;
            ct++;
        }

        for (auto it : v)
        {
            if(it==0) continue;
            cout << it << " ";
        }
    }
}