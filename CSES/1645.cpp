#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int nsv[n];

    stack<pair<int, int>> st;

    for (int i = n-1; i >=0; i--)
    {
        while (!st.empty() && st.top().first > a[i])
        {
            nsv[st.top().second] = (i+1);
            st.pop();
        }
        st.push({a[i], i});
    }
    while (!st.empty())
    {
        nsv[st.top().second] = 0;
        st.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << nsv[i] << " ";
    } 
}