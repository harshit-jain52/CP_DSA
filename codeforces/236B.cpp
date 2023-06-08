#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int N = 1e6 + 10;
const ull M = 1073741824;

vector<int> divis(N, 1);

void divisors()
{
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            divis[j]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, i, j, k;
    cin >> a >> b >> c;
    ull sum = 0;
    divisors();

    for (i = 1; i <= a; i++)
    {
        for (j = 1; j <= b; j++)
        {
            for (k = 1; k <= c; k++)
            {
                // cout << divis[i * j * k] << endl;
                sum = (sum % M + divis[i * j * k] % M) % M;
            }
        }
    }
    cout << sum;
}