#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k; cin >> n >> k;
    string s; cin >> s;
    
    int ct = 0;
    stack<char>st;
    for(int i=0;i<n;i++){
        if(!st.empty() && st.top()==s[i]){
            st.pop();
            ct++;
        }
        else st.push(s[i]);
    }
    
    int pl = (ct+1)%k;
    cout << ((pl==0)?k:pl)<<endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}