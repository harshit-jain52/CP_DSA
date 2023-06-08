#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    char S[n + 1];
    int I[n];
    cin >> S;

    for (int i = 0; S[i] != '\0'; i++)
    {
        I[i] = S[i] - '0';
    }

    int count = 0;

    if (n == 1)
    {
        if (n != 0 && k >= 1)
        {
            I[0] = 0;
            count++;
        }
    }
    else
    {
        if (I[0] != 1 && k >= 1)
        {
            I[0] = 1;
            count++;
        }

        for (int i = 1; i < n && count < k; i++)
        {
            if (I[i] != 0)
            {
                I[i] = 0;
                count++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << I[i];
    }

    return 0;
}