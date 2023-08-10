#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ll n, k;
    cin >> n >> k;

    if (k == 1)
        cout << n;
    else
    {
        ll nums[61];
        nums[0] = 1;
        for (int i = 1; i < 61; i++)
        {
            nums[i] = nums[i - 1] * 2;
        }

        auto it = upper_bound(nums, nums + 61, n) - nums;
        cout << nums[it] - 1;
    }
}