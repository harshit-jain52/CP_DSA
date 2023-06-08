#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
vector<bool> isPrime(N, 1);
vector<int> lp(N, 0);

void lowestPrimeFactor()
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            lp[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                if (lp[j] == 0)
                {
                    lp[j] = i;
                }
            }
        }
    }
}

int main()
{
    lowestPrimeFactor();
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        if (n == 1)
            cout << "YES";
        else
        {
            if (lp[n] > m)
                cout << "YES";
            else
                cout << "NO";
        }
        cout << endl;
    }
}