#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    set<int>st;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        st.insert(a);
    }
    
    long long sz = st.size();
    cout << sz*(sz-1)/2 << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}