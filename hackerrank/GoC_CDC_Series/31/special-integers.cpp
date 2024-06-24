#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;

int sumOfDig(ll num){
    int ans = 0;
    while(num){
        ans += num%10;
        num/=10;
    }
    return ans;
}

void solve(){
    int a,b,c; cin >> a >> b >> c;
    
    vector<ll>sp;
    for(int i=0;i<=81;i++){
        ll f = 1;
        for(int j=0;j<a;j++) f*=i;
        
        ll x = b*f+c;
        if(x<0 || x>INF) continue;
        if(sumOfDig(x) == i) sp.push_back(x);
    }
    
    if(sp.size()){
        sort(sp.begin(),sp.end());
        cout << sp.size() << endl;
        for(auto it: sp) cout << it << " ";
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}