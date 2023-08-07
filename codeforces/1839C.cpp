#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        if (a[n - 1] == 1)
            cout << "NO";
        else
        {
            cout << "YES" << endl;
            vector<int> steps;
            int ct0 = 0, ct1 = 0;

            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i] == 0)
                {
                    if (i > 0 && a[i - 1] == 1)
                    {
                        while (ct0 > 0)
                        {
                            steps.push_back(0);
                            ct0--;
                        }
                    }
                    else
                    {
                        ct0++;
                        if (i == 0)
                        {
                            while (ct0 > 0)
                            {
                                steps.push_back(0);
                                ct0--;
                            }
                        }
                    }
                }
                else
                {
                    ct1++;
                    if (i == 0 || (i > 0 && a[i - 1] == 0))
                    {
                        int tmp = ct1;
                        while (ct1 > 0)
                        {
                            steps.push_back(0);
                            ct1--;
                        }
                        steps.push_back(tmp);
                    }
                }
            }

            for (auto it : steps)
            {
                cout << it << " ";
            }
        }
        cout << endl;
    }
}