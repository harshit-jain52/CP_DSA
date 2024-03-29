#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef unsigned long long ull;

ull summation(ull k, int ct, ull n)
{
    ull sum = 1;
    ull tmp = k;
    while (ct--)
    {
        if (ULLONG_MAX - tmp < sum)
            return ULLONG_MAX;
        
        sum += tmp;
        if (sum > n)
            return sum;

        if (ULLONG_MAX / k < tmp && ct != 0)
            return ULLONG_MAX;
            
        tmp *= k;
    }
    return sum;
}

bool solve(ull n)
{
    for (int i = 2; i < 64; i++)
    {
        ull lo = 2, hi = sqrt(n) + 2, mid;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            ull sum = summation(mid, i, n);

            if (sum == n)
                return true;

            if (sum > n)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ull n;
        cin >> n;

        if (solve(n))
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}