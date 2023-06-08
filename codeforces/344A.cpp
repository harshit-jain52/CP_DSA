#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, count = 1;
    cin >> n;
    vector<string> v;
    string temp;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    for (i = 1; i < n; i++)
    {
        if (v[i] != v[i - 1])
        {
            count++;
        }
    }

    cout << count;
}