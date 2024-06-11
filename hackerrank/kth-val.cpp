#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m,q;
        cin >> n >> m >> q;
        int a[n+1];
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int>ct(n+2,0);
        while(m--){
            int l,r;
            cin >> l >> r;
            ct[l]++;
            ct[r+1]--;
        }
        for(int i=1;i<=n;i++) ct[i]+=ct[i-1];
        
        vector<pair<int,int>>pp(n);
        for(int i=1;i<=n;i++) pp[i-1] = make_pair(a[i],ct[i]);
        sort(pp.begin(),pp.end());
        ll ctpref[n+1];
        ctpref[0]=0;
        for(int i=1;i<=n;i++) ctpref[i]=ctpref[i-1]+pp[i-1].second;
        while(q--){
            ll k;
            cin >> k;
            int idx = lower_bound(ctpref,ctpref+n+1,k) - ctpref;
            if(idx>n) cout << -1;
            else cout << pp[idx-1].first;
            cout << " ";
        }
        cout << endl;
    }
}

// https://www.hackerrank.com/contests/codenite-v1/challenges/kth-value