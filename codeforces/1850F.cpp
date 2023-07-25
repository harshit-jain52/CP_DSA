#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int N = 2e5 + 10;
vector<int> divis[N];

void divisors()
{   
    divis[1].push_back(1);
    for (int i = 2; i < N; i++)
    {
        divis[i].push_back(1);
        for (int j = i; j < N; j += i)
        {
            divis[j].push_back(i);
        }
    }
}

int main()
{
    divisors();
    int t;
    cin >> t;
    while (t--)
    {
        map<int, int> ct;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            ct[tmp]++;
        }
        int ans = 0, maxct = 0;
        for (int i = 1; i <= n; i++)
        {
            int tmpsum = 0;
            for (auto it : divis[i])
            {
                tmpsum += ct[it];
            }
            ans = max(ans, tmpsum);
        }
        cout << ans << endl;
    }
}