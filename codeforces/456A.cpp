#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cin >> n;

    int atemp, btemp;
    vector<pair<int, int>> laptops;

    for (i = 0; i < n; i++)
    {
        cin >> atemp >> btemp;
        laptops.push_back({atemp, btemp});
    }

    sort(laptops.begin(), laptops.end());

    for (i = 1; i < n; i++)
    {
        if (laptops[i].second < laptops[i - 1].second)
        {
            break;
        }
    }

    if (i == n)
    {
        cout << "Poor Alex";
    }
    else
    {
        cout << "Happy Alex";
    }
}