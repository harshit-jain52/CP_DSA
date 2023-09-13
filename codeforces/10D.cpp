#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void LCIS(int arr1[], int n, int arr2[], int m)
{
    // keeping arr2 smaller
    if (m < n)
        return LCIS(arr2, m, arr1, n);

    vector<int> dp(m, 0);
    vector<int> hash(m, -1);

    for (int i = 0; i < n; i++)
    {
        int curr = 0, last = -1;
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                if (curr + 1 > dp[j])
                {
                    dp[j] = max(curr + 1, dp[j]);
                    hash[j] = last;
                }
            }
            else if (arr1[i] > arr2[j])
            {
                if (dp[j] > curr)
                {
                    curr = dp[j];
                    last = j;
                }
            }
        }
    }

    int maxlen = 0, idx = -1;

    for (int j = 0; j < m; j++)
    {
        if (dp[j] > maxlen)
        {
            maxlen = dp[j];
            idx = j;
        }
    }

    // for (int j = 0; j < m; j++)
    // {
    //     cout << dp[j] << " ";
    // }
    // cout << endl;
    // for (int j = 0; j < m; j++)
    // {
    //     cout << hash[j] << " ";
    // }
    // cout << endl;

    int len = maxlen;
    vector<int> ans;
    
    while (idx != -1)
    {
        ans.push_back(arr2[idx]);
        idx = hash[idx];
    }

    cout << maxlen << endl;
    for (int i = maxlen - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;
    int arr2[m];
    for (int j = 0; j < m; j++)
    {
        cin >> arr2[j];
    }

    LCIS(arr1, n, arr2, m);
}