#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, K;
        cin >> n >> K;

        int nums[n];
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }

        int k = K + 2;
        deque<int> dec, inc;
        int maxdiff = 0;
        for (int i = 0; i < n; i++)
        {
            while (!dec.empty() && nums[dec.back()] < nums[i])
            {
                dec.pop_back();
            }
            dec.push_back(i);

            while (!inc.empty() && nums[inc.back()] > nums[i])
            {
                inc.pop_back();
            }
            inc.push_back(i);

            if (dec.front() < i - k + 1)
                dec.pop_front();

            if (inc.front() < i - k + 1)
                inc.pop_front();

            maxdiff = max(maxdiff, nums[dec.front()] - nums[inc.front()]);
        }

        cout << maxdiff << endl;
    }
}