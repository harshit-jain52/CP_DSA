#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
typedef pair<int,int> pii;
#define F first
#define S second

int binpow(int a, int b){
    int ans = 1;
    while(b){
        if(b&1) ans = (ans*1LL*a)%M;
        a = (a*1LL*a)%M;
        b>>=1;
    }
    return ans;
}

void solve(){
    int n,k,m; cin >> n>>k>>m;
    multiset<pii>ms;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        ms.insert({a[i],i});
    }
    
    if(k==1){
        for(int i=0;i<n;i++) cout << a[i]<<" ";
        cout << endl;
        return;
    }
    
    int ct = 0;
    for(ct=0;ct<m;ct++){
        pii it1 = *(ms.begin());
        pii it2 = *(ms.rbegin());
        // cout << it1.F<<" "<<it2.F<<endl;
        
        if(it1.F*1LL*k>it2.F) break;
        
        ms.erase(ms.begin());
        ms.insert({it1.F*k,it1.S});
    }
    
    vector<pii>vec;
    for(auto it: ms) vec.push_back(it);
    
    int left = m-ct;
    int pow = left/n, rem = left%n;
    int ans[n], ex = binpow(k,pow);
    
    for(int i=0;i<rem;i++) vec[i].F = (vec[i].F*1LL*k)%M;
    
    for(int i=0;i<n;i++) ans[vec[i].S] = (vec[i].F*1LL*ex)%M;
    
    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << '\n';
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}