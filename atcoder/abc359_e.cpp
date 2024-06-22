#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    int n; cin >> n;
    ll h[n+1];
    for(int i=1;i<=n;i++) cin >> h[i];

    vector<int>pge(n+1,0);
    stack<int>st;
    for(int i=1;i<=n;i++){
        while(!st.empty() && h[st.top()]<h[i]) st.pop();
        if(!st.empty()) pge[i]=st.top();
        st.push(i);
    }

    ll ans[n+1];
    ans[0]=1;

    for(int i=1;i<=n;i++){
        int last = pge[i];
        ans[i] = ans[last]+(i-last)*h[i];
    }

    for(int i=1;i<=n;i++) cout << ans[i]<<" ";
}