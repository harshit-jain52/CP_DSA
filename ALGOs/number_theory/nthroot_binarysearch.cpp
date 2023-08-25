#include <bits/stdc++.h>
using namespace std;

double eps = 1e-6; // precision/10

double multiply(double num, int n)
{
    double ans = 1;
    while (n--)
    {
        ans *= num;
    }
    return ans;
}

int main()
{
    double x;
    int n;
    cin >> x >> n;
    double lo = 1, hi = x, mid;

    while (hi - lo > eps)
    {
        mid = (hi + lo) / 2;

        if (multiply(mid, n) < x)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }

    cout << lo << "\n" << hi;    
}