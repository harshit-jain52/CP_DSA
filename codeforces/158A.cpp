#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, count, temp, score_k;
    cin >> n >> k;
    count = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> temp;

        if (temp == 0)
        {
            break;
        }

        if (i < k)
        {
            count++;
        }
        else if (i == k)
        {
            score_k = temp;
            count++;
        }
        else if (i > k && temp == score_k)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}