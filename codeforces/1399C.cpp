#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j, num;
        cin >> n;
        int w[n];
        vector<int> wtct(101, 0);

        for (i = 0; i < n; i++)
        {
            cin >> w[i];
        }
        sort(w, w + n);

        for (num = 2; num <= 100; num++)
        {
            for (i = 0, j = n - 1; i < j;)
            {
                int sum = w[i] + w[j];
                if (sum == num)
                {
                    wtct[num]++;
                    i++;
                    j--;
                }
                else if (sum < num)
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
        }

        cout << *max_element(wtct.begin(), wtct.end()) << endl;
    }
}