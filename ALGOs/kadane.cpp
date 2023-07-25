#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
Given an integer array nums, find the
subarray with the largest sum, and return its sum.

Most Optimal Solution: Kadane's Algo; TC:O(N); Extra SC: O(1)
*/
ll maxSubArray(vector<int> &nums)
{
    ll max_so_far = INT_MIN, max_ending_here = 0, i;

    for (i = 0; i < nums.size(); i++)
    {
        max_ending_here += nums[i];
        max_so_far = max(max_so_far, max_ending_here);
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
        }
    }

    // if empty subarray is allowed, return 0 if max_so_far < 0
    return max_so_far;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << maxSubArray(v);
}