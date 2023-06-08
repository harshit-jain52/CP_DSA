#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, k, n, i, init, count;
    cin >> t;

    while (t--)
    {
        cin >> k >> n;
        set<int> arr;
        init = 1;
        arr.insert(init);
        for (i = 1; init + i <= n && arr.size() < k; i++)
        {
            init += i;
            arr.insert(init);
        }
        if (arr.size() < k)
        {
            for (i = n; arr.size() < k; i--)
            {
                if (arr.find(i) == arr.end())
                {
                    arr.insert(i);
                }
            }
        }

        for (int it : arr)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}