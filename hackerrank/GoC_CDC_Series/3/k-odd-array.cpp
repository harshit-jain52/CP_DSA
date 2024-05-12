#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto atmostK = [&](int K) -> ll
    {
        if (K < 0)
            return 0;
        int tail = 0, head = -1, curr = 0;
        ll ct = 0;
        while (tail < n)
        {
            while (head + 1 < n && curr + a[head + 1] % 2 <= K)
            {
                head++;
                curr += a[head] % 2;
            }
            ct += (head - tail + 1);
            if (head >= tail)
            {
                curr -= a[tail] % 2;
                tail++;
            }
            else
            {
                tail++;
                head = tail - 1;
            }
        }
        return ct;
    };

    cout << (atmostK(k) - atmostK(k - 1));
}