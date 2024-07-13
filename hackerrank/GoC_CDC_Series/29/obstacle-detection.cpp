#include <bits/stdc++.h>
using namespace std;

void solve(){
    set<int>st;
    int q; cin >> q;
    while(q--){
        int tp; cin >> tp;
        if(tp==1){
            int x; cin >> x;
            st.insert(x);
        }
        else{
            int l,sz; cin >> l >> sz;
            auto it = st.lower_bound(l);
            if(it!=st.end() && (*it)<=l+sz) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}