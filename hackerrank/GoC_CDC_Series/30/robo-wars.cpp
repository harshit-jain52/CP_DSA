#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    stack<int>st;
    
    vector<int>vec1;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        if(a>0) st.push(a);
        else{
            while(!st.empty() && st.top()<abs(a)) st.pop();
            if(st.empty()) vec1.push_back(a);
        }
    }
    
    vector<int>vec2;
    while(!st.empty()){
        vec2.push_back(st.top());
        st.pop();
    }
    reverse(vec2.begin(),vec2.end());
    
    cout << vec1.size()+vec2.size()<<endl;
    for(int i: vec1) cout << i << " ";
    for(int i: vec2) cout << i << " ";
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}