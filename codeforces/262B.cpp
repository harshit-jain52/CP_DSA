#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k, temp, i, income = 0;
    cin >> n >> k;
    vector<ll> pos, neg;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp >= 0)
        {
            pos.push_back(temp);
        }
        else
        {
            neg.push_back(temp);
        }
    }

    if (k <= neg.size())
    {
        for (i = 0; i < k; i++)
        {
            income += -1 * neg[i];
        }
        for (; i < neg.size(); i++)
        {
            income += neg[i];
        }
        for (i = 0; i < pos.size(); i++)
        {
            income += pos[i];
        }
    }
    else
    {
        ll diff = k - neg.size();
        if (diff % 2 == 0)
        {
            for (i = 0; i < neg.size(); i++)
            {
                income += -1 * neg[i];
            }
            for (i = 0; i < pos.size(); i++)
            {
                income += pos[i];
            }
        }
        else
        {
            if (neg.size() == 0)
            {
                pos[0] *= (-1);
                for (i = 0; i < pos.size(); i++)
                {
                    income += pos[i];
                }
            }
            else if (pos.size() == 0)
            {
                neg[neg.size() - 1] *= (-1);
                for (i = 0; i < neg.size(); i++)
                {
                    income += -1 * neg[i];
                }
            }
            else
            {
                for (i = 0; i < neg.size() - 1; i++)
                {
                    income += -1 * neg[i];
                }
                for (i = 1; i < pos.size(); i++)
                {
                    income += pos[i];
                }
                income += -1 * min(abs(neg[neg.size() - 1]), pos[0]);
                income += max(abs(neg[neg.size() - 1]), pos[0]);
            }
        }
    }

    cout << income;
}