#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,c; cin >> n >> c;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    
    int lo = *min_element(a,a+n), hi = *max_element(a,a+n), mid;
    int ans = lo;
    while(lo<=hi){
        mid = (lo+hi)/2;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            if(a[i]>=mid) vec[i]=1;
            else vec[i]=-1;
        }
        
        int sum=0; bool flag = false;
        for(int i=0;i<c;i++) sum += vec[i];
        if(sum>0) flag = true;
        
        for(int i=c;i<n;i++){
            sum-=vec[i-c];
            sum+=vec[i];
            if(sum>0) flag = true;
        }
        
        if(flag){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    
    int ct = 0;
    for(int i=0;i<n;i++) ct += (a[i]>=ans);
    cout << ct << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}