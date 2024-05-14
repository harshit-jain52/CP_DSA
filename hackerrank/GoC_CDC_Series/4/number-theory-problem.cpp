#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// (x-N)(y-N) = N^2
int main()
{
    int N;
    cin >> N;
    ll div = 1; // number of divisors of N^2
    for (int i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            int ct = 0;
            while (N % i == 0)
            {
                ct++;
                N /= i;
            }
            div *= (2 * ct + 1);
        }
    }
    if (N > 1)
        div *= 3;

    cout << div;
}