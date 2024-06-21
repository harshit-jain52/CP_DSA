#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k; cin >> n >> k;
    set<int>st;
    
    for(int i=0;i<n;i++){
        int a; cin >> a;
        st.insert(a);
    }
    
    int sz = st.size();
    if(sz<k){
        cout << 0 << endl;
        return;
    }
    
    vector<int>vec;
    for(auto it: st) vec.push_back(it);
    
    vector<bool>take(sz,true);
    int ans=0;    
    for(int bit=30;bit>=0;bit--){
        int ct=0;
        for(int i=0;i<sz;i++) if(take[i] && ((vec[i]>>bit)&1)) ct++;
        
        if(ct>=k){
            ans += (1<<bit);
            for(int i=0;i<sz;i++) if(take[i] && !((vec[i]>>bit)&1)) take[i]=false;
        }
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}