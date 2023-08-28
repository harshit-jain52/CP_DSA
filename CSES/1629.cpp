#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> time(n);

    for (int i = 0; i < n; i++)
    {
        cin >> time[i].second >> time[i].first;
    }
    sort(time.begin(), time.end()); // Earliest Finish strategy

    stack<pair<int, int>> st;

    st.push(time[0]);

    for (int i = 1; i < n; i++)
    {
        if (time[i].second >= st.top().first)
            st.push(time[i]);
    }

    cout << st.size();
}