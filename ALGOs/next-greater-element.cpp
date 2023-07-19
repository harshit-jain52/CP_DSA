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
    
    int nge[n];

    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first < a[i])
        {
            nge[st.top().second] = a[i];
            st.pop();
        }
        st.push({a[i], i});
    }
    while (!st.empty())
    {
        nge[st.top().second] = -1;
        st.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << nge[i] << " ";
    } 
}