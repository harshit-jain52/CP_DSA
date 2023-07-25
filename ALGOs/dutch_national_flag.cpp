#include <bits/stdc++.h>
using namespace std;

/*
Given an arr consisting of no's either 0, 1 or 2. Sort it

Most Optimal Solution: Dutch National Flag algorithm; TC: O(N); Extra SC: O(1)
*/

void sortNums(vector<int> &nums)
{
    int n = nums.size();
    int lo = n - 1, mid = 0, hi = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            lo = i;
            break;
        }
    }
    hi = lo;
    for (int i = n - 1; i >= lo; i--)
    {
        if (nums[i] != 2)
        {
            hi = i;
            break;
        }
    }
    mid = lo;
    while (mid <= hi)
    {
        if (nums[mid] == 0)
        {
            swap(nums[lo], nums[mid]);
            lo++;
            mid++;
        }
        else if (nums[mid] == 2)
        {
            swap(nums[mid], nums[hi]);
            hi--;
        }
        else
        {
            mid++;
        }
    }
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

    sortNums(v);
    
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}