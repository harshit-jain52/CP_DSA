#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second

void solve(){
    int n,k;
    cin >> n >> k;

    multiset<pii>ms;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        ms.insert({a,n-i});
    }

    ll ct = 0;
    while(!ms.empty()){
        auto it = ms.begin();
        pii pp = *it;
        ms.erase(it);

        if(pp.F>k) break;
        int num = min(pp.S,k/pp.F);
        ct += num;
        k -= num*pp.F;
        pp.S -= num;

        if(pp.S>0) ms.insert(pp);
    }

    cout << ct << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}