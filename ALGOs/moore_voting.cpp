#include <bits/stdc++.h>
using namespace std;

/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than [n / 2] times.
You may assume that the majority element always exists in the array.

Most Optimal Solution: Moore's Voting algorithm; TC: O(N); Extra SC: O(1)
*/

int majorityElement(vector<int> &nums)
{
    int cnt = 0, el = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            el = nums[i];
            cnt++;
        }
        else
        {
            if (nums[i] == el)
                cnt++;
            else
                cnt--;
        }
    }

    //in the case where majority element might not exist, iterate through the array to count the occurences of el

    return el;
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
    cout << majorityElement(v);
}