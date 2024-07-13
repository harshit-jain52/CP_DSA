#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc2(vector<int>&pos){
    int sz = pos.size();
    ll ct = 0;
    for(int i=0;i<sz-1;i++){
        int len = pos[i+1]-pos[i]-1;
        ct += len*1LL*(len+1)/2;
    }

    return ct;
}

ll calc(vector<int>&arr){
    int n = arr.size();
    int mn = *min_element(arr.begin(),arr.end()), mx = *max_element(arr.begin(),arr.end());

    if(mn==mx) return n*1LL*(n+1)/2;

    ll ans = 0;

    vector<int>pos;

    pos.push_back(-1);
    for(int i=0;i<n;i++) if(arr[i]==mn) pos.push_back(i);
    pos.push_back(n);
    ll ct1=calc2(pos);

    pos.clear();
    pos.push_back(-1);
    for(int i=0;i<n;i++) if(arr[i]==mx) pos.push_back(i);
    pos.push_back(n);
    ll ct2=calc2(pos);

    pos.clear();
    pos.push_back(-1);
    for(int i=0;i<n;i++) if(arr[i]==mx || arr[i]==mn) pos.push_back(i);
    pos.push_back(n);
    ll ct12=calc2(pos);

    return (n*1LL*(n+1)/2 - (ct1+ct2-ct12));
}

void solve(){
    int n; cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    ll ans = calc(arr);

    int mn = *min_element(arr.begin(),arr.end());
    int mnct=0;
    vector<int>tmp;
    for(int i=0;i<n;i++){
        if(arr[i]==mn) mnct++;
        else tmp.push_back(arr[i]);
    }

    if(mnct==1) ans = max(ans,calc(tmp));

    tmp.clear();
    int mx = *max_element(arr.begin(),arr.end());
    int mxct=0;
    for(int i=0;i<n;i++){
        if(arr[i]==mx) mxct++;
        else tmp.push_back(arr[i]);
    }

    if(mxct==1) ans = max(ans,calc(tmp));

    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}