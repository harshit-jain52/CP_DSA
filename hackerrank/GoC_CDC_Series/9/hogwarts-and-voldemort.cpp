#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second

void solve(){    
    int n; cin >> n;
    int p[n+1];
    for(int i=0;i<=n;i++) cin >> p[i];
    
    stack<pii>st;
    st.push({INT_MIN,0});
    
    for(int i=0;i<=n;i++){
        int l = i-p[i], r = i+p[i];

        // cout << l << " "<<r<<" "<<st.top().F<<" "<<st.top().S<<endl;
        if(l>st.top().S) continue;
        
        if(st.top().S<r){
        	while(st.top().F>=l && st.top().S<r) st.pop();
        	if(st.top().S<n) st.push({st.top().S,r});
        }
    }

    if(st.top().S < n) cout << -1 << endl;
    else cout << st.size()-1<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while(t--) solve();
}