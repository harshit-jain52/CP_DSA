#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    cin >> n;
    vector<ll> odd;
    ll temp, sum = 0;

    for (i = 0; i < n; i++)
    {
        cin >> temp;

        if (temp % 2 == 0)
        {
            sum += temp;
        }
        else
        {
            odd.push_back(temp);
        }
    }

    sort(odd.begin(), odd.end());
    if (odd.size() % 2 == 0)
    {
        i = 0;
    }
    else
    {
        i = 1;
    }
    for (; i < odd.size(); i++)
    {
        sum += odd[i];
    }

    cout << sum;
}