#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int freq[N];

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    int k = 0;
    for (int i = 1; i < N; i++)
    {
        if (freq[i])
        {
            k++;
            freq[i] = 0;
        }
    }

    int ans = n, ct = 0;
    int tail = 0, head = -1;

    auto insert = [&](int num) -> void
    {
        freq[num]++;
        if (freq[num] == 1)
            ct++;
    };

    auto remove = [&](int num) -> void
    {
        freq[num]--;
        if (freq[num] == 0)
            ct--;
    };

    while (tail < n)
    {
        while (head + 1 < n && ct < k)
        {
            head++;
            insert(a[head]);
        }
        if (ct == k)
            ans = min(ans, head - tail + 1);
        remove(a[tail]);
        tail++;
    }

    cout << ans;
}