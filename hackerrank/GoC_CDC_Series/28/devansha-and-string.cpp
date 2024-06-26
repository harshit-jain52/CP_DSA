#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    stack<char>st;
    for(int i=0;i<n;i++){
        if(!st.empty() && s[i]==st.top()) st.pop();
        else st.push(s[i]);
    }
    
    string res="";
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    
    reverse(res.begin(),res.end());
    cout << res.length()<<" "<<res<<endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}