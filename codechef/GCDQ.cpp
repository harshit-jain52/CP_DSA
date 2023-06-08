#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, N, Q, i, j, L, R;
    cin >> T;
    while (T--)
    {
        cin >> N >> Q;
        int A[N + 1];
        int hash1[N + 2];
        int hash2[N + 2];
        A[0] = hash1[0] = hash2[N + 1] = 0;
        for (i = 1; i <= N; i++)
        {
            cin >> A[i];
        }

        for (i = 1; i <= N; i++)
        {
            j = N + 1 - i;
            hash1[i] = __gcd(hash1[i - 1], A[i]);
            hash2[j] = __gcd(hash2[j + 1], A[j]);
        }

        // for (i = 0; i <= N; i++)
        // {
        //     cout << A[i] << " " << hash1[i] << " " << hash2[i] << endl;
        // }

        while (Q--)
        {
            cin >> L >> R;
            cout << __gcd(hash1[L - 1], hash2[R + 1]) << endl;
        }
    }
}