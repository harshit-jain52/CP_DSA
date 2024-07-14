#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+9;
const int P = 31;
int p_pow[50];

void solve(){
    int n; cin >> n;
    vector<string>vec(n);
    for(int i=0;i<n;i++) cin >> vec[i];

    sort(vec.begin(),vec.end());
    map<int,int>mp;
    int idx = n;

    for(int i=0;i<n;i++){
        string s = vec[i];
        int sz = s.size();
        vector<int>pref(sz+1,0);
        for(int j=0;j<sz;j++){
            pref[j+1]=((pref[j]*1LL*P)%M + (s[j]-'a'+1))%M;
            if(mp.find(pref[j+1])!=mp.end()) idx = min(idx,mp[pref[j+1]]);
        }
        if(mp.find(pref[sz])==mp.end()) mp[pref[sz]]=i;
    }

    if(idx<n) cout << vec[idx] << endl;
    else cout << -1 << endl;
}

int main(){
    p_pow[0]=1;
    for(int i=1;i<50;i++) p_pow[i]=(P*1LL*p_pow[i-1])%M;

    int t; cin >> t;
    while(t--) solve();
}