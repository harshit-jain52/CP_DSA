#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second

void solve(){
    int n,m; cin >> n >> m;
    vector<ll>a(n+1);
    ll sum = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum += a[i];
    }
    
    vector<pii>sales(m+1);
    sales[0]={0,0};
    for(int i=1;i<=m;i++) cin >> sales[i].F >> sales[i].S;
      
    sort(sales.begin(),sales.end());
    
    ll lo=0,hi=2*sum,mid;
    ll ans = hi;
    
    while(lo<=hi){
        mid = (lo+hi)/2;
        ll curr=mid, left=sum;
        vector<ll>req=a;

        for(int i=m;i>0;i--){
            if(sales[i].F>mid) continue;

            curr = min(curr,1LL*sales[i].F);
            ll spend = min(curr,req[sales[i].S]);
            req[sales[i].S] -= spend;
            curr -= spend;
            left -= spend;
        }
        
        if(left+sum<=mid){
            ans = mid;
            hi = mid-1;
        }
        else lo=mid+1;
    }
    
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}