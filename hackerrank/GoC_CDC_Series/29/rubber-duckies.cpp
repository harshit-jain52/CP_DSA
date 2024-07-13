#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
#define F first
#define S second

void solve(){
    int n,q; cin >> n >> q;
    vector<pii>toys(n);
    for(int i=0;i<n;i++) {
        cin >> toys[i].F;
        toys[i].S = i+1;
    }

    sort(toys.begin(),toys.end());
    vector<int>pos(n+1);
    for(int i=0;i<n;i++) pos[toys[i].S]=i;

    vector<ll>pref(n);
    for(int i=0;i<n;i++){
        pref[i]=toys[i].F;
        if(i>0) pref[i]+=pref[i-1];
    }

    while(q--){
        int k; cin >> k;
        ll c; cin >> c;
        vector<int>ind(k);
        for(int i=0;i<k;i++){
            int x; cin >> x;
            ind[i]=pos[x];
        }

        sort(ind.begin(),ind.end());

        int last = upper_bound(pref.begin(),pref.end(),c)-pref.begin();
        int ct = 0;
        for(int i=0;i<k;i++){
            if(ind[i]>=last) break;
            ct++;
            c += toys[ind[i]].F;
            last = upper_bound(pref.begin(),pref.end(),c)-pref.begin();
        }

        cout << last-ct << " ";
    }
    cout << endl;    
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}