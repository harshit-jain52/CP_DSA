#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int n, k;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cin >> k;

    deque<int> dec;
    for (int i = 0; i < n; i++)
    {
        while (!dec.empty() && nums[dec.back()] < nums[i])
        {
            dec.pop_back();
        }
        dec.push_back(i);

        if (dec.front() < i - k + 1)
            dec.pop_front();

        if (i >= k - 1)
            cout << (nums[dec.front()]) << " ";
    }
}