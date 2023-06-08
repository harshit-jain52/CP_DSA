#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v)
{
    for (auto it : v)
    {
        cout << it << " ";
    }
}

int main()
{
    int n, k, i, a;
    cin >> n >> k;
    vector<int> segments;

    for (i = 0; i < n * k; i++)
    {
        segments.push_back(i + 1);
    }

    // printVector(segments);

    vector<vector<int>> given(k);
    for (i = 0; i < k; i++)
    {
        cin >> a;

        segments[a - 1] = 0;
        given[i].push_back(a);
    }

    for (auto it = segments.begin(); it != segments.end(); it++)
    {
        if (*(it) == 0)
        {
            segments.erase(it);
            --it;
        }
    }

    // printVector(segments);
    int j = 0;
    for (i = 0; i < k; i++)
    {
        for (int count = 0; count < n - 1; count++)
        {
            given[i].push_back(segments[j]);
            j++;
        }
    }

    for (i = 0; i < k; i++)
    {
        printVector(given[i]);
        cout << endl;
    }
}