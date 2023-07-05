#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    if (n % 4 == 3 || n % 4 == 0)
    {
        cout << "YES" << endl;
        vector<int> v1;
        vector<int> v2;
        if (n % 4 == 3)
        {
            v1.push_back(1);
            v1.push_back(2);
            v2.push_back(3);
            for (int i = 4; i <= n; i++)
            {
                int rem = i % 4;
                if (rem == 0 || rem == 3)
                    v1.push_back(i);
                else
                    v2.push_back(i);
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                int rem = i % 4;
                if (rem == 0 || rem == 1)
                    v1.push_back(i);
                else
                    v2.push_back(i);
            }
        }
        cout << v1.size() << endl;
        for (auto num : v1)
            cout << num << " ";
        cout << endl
             << v2.size() << endl;
        for (auto num : v2)
            cout << num << " ";
    }
    else
    {
        cout << "NO" << endl;
    }
}