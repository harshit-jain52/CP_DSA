#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    int arr1[n],arr2[n];
    ll pref[n+1];
    pref[0]=0;
    
    for(int i=0;i<n;i++) cin >> arr1[i];
    for(int i=0;i<n;i++) {
        cin >> arr2[i];
        pref[i+1] = pref[i]+arr2[i];
    }
    
    ll ans = 0;
    int head=-1,tail=0;
    set<int>st;
    
    while(tail<n){
        while(head+1<n && st.find(arr1[head+1])==st.end()){
            head++;
            st.insert(arr1[head]);
        }
        
        ans = max(ans,pref[head+1]-pref[tail]);
        
        if(head>=tail){
            st.erase(arr1[tail]);
            tail++;
        }
        else{
            tail++;
            head=tail-1;
        }
    }
    
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}