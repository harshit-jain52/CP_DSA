#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (1)
    {
        double n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        double prob;

        if (n > m)
        {
            prob = 0;
        }
        else
        {
            prob = (m + 1 - n) / (m + 1);
        }

        printf("%.6f\n", prob);
    }
}