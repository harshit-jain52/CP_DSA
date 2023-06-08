#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, temp;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> albums[n];
        vector<pair<int, int>> maxcool;
        vector<int> arranged;

        for (int i = 0; i < n; i++)
        {
            cin >> k;
            vector<int> tracks;
            int max = 0;
            for (int j = 0; j < k; j++)
            {
                cin >> temp;
                tracks.push_back(temp);
                if (temp > max)
                {
                    max = temp;
                }
            }
            maxcool.push_back({max, i});
            albums[i] = tracks;
        }

        sort(maxcool.begin(), maxcool.end());

        for (auto it : maxcool)
        {
            int index = it.second;
            for (int i = 0; i < albums[index].size(); i++)
            {
                arranged.push_back(albums[index][i]);
            }
        }
        int impressions = 1;
        for (int i = 1; i < arranged.size(); i++)
        {
            if (arranged[i] > arranged[i - 1])
            {
                impressions++;
            }
            arranged[i] = max(arranged[i], arranged[i - 1]);
        }

        cout << impressions << endl;
    }
}