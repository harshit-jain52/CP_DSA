#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    
    vector<int>ct(n,0), day(n,-1);
    stack<int>st;
    
    for(int i=0;i<n;i++){
        while(!st.empty() && (a[st.top()]>=a[i] || ct[st.top()]==day[st.top()])) st.pop();
        
        if(!st.empty()) day[i]= ++ct[st.top()];
        st.push(i);
    }
    
    int ans = *max_element(day.begin(),day.end());
    cout << ((ans!=-1)?ans:0);
}