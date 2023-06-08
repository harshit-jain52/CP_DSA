/*
https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/hacker-with-prime-bebe28ac/
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e6 + 10;
int hp[N];
int canRemove[N];
int hsh[N];

vector<int> distinctPrimeFactors(int x)
{
    vector<int> ans;
    while (x > 1)
    {
        int pf = hp[x];
        while (x % pf == 0)
            x /= pf;
        ans.push_back(pf);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < N; i++)
    {
        if (hp[i] == 0)
        {
            for (int j = i; j < N; j += i)
            {
                hp[j] = i;
            }
        }
    }

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        hsh[tmp] = 1;
    }

    for (int i = 2; i < N; i++)
    {
        if (hsh[i])
        {
            for (ll j = i; j < N; j *= i)
            {
                canRemove[j] = 1;
            }
        }
    }

    while (q--)
    {
        int x;
        cin >> x;
        vector<int> pf = distinctPrimeFactors(x);
        bool isPossible = false;
        for (int i = 0; i < pf.size(); i++)
        {
            for (int j = 0; j < pf.size(); j++)
            {
                int prod = pf[i] * pf[j];
                if (i == j && x % prod != 0)
                {
                    continue;
                }
                int toRemove = x / prod;
                if (canRemove[toRemove] || toRemove==1)
                {
                    isPossible = true;
                    break;
                }
            }
            if (isPossible)
            {
                break;
            }
        }

        cout << (isPossible ? "YES\n" : "NO\n");
    }
}