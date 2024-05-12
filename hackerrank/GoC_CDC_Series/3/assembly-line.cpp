#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    multiset<int> ms;

    int lge[n];
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && h[st.top()] < h[i])
            st.pop();
        if (st.empty())
            lge[i] = -1;
        else
            lge[i] = st.top();

        st.push(i);
    }

    ll ct = 0;
    for (int i = 0; i < n; i++)
        ct += (i - lge[i] - 1);
    cout << ct;
}