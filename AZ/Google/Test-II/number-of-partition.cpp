#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    ll arr[n];

    map<ll,int> left,right;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(left.find(arr[i])==left.end()) left[arr[i]]=i;
        right[arr[i]]=i;
    }

    ll pref[n],suff[n];
    pref[0]=arr[0], suff[n-1]=arr[n-1];
    for(int i=1;i<n;i++){
        pref[i] = pref[i-1]+arr[i];
        suff[n-1-i] = suff[n-i]+arr[n-1-i];
    }

    int ct0=0;
    int ans = 0;
    map<ll,int>ctr;
    for(int i=0;i<n-1;i++){
        ll diff = pref[i]-suff[i+1];
        if(diff==0) ct0++;
        ctr[diff]++;
    }

    map<ll,int>ctl;
    for(int i=0;i<n;i++){
        if(i>0) ctl[suff[i]-pref[i-1]]++;
        ans = max(ans,ctl[arr[i]]+ctr[arr[i]]);
        if(i<n-1) ctr[pref[i]-suff[i+1]]--;
    }
    ans = max(ct0,ans);
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}