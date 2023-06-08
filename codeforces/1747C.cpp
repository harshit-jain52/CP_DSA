#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long a, temp, mina;
        vector<long long> nums;
        int i, count = 0;
        cin >> a;
        for (i = 1; i < n; i++)
        {
            cin >> temp;
            nums.push_back(temp);
        }
        mina = *min_element(nums.begin(), nums.end());

        if (a <= mina)
        {
            cout << "Bob";
        }
        else
        {
            cout << "Alice";
        }
        cout << endl;
    }
}