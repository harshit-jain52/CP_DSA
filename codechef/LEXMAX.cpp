#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
    int n;
    cin >> n;
    int a[n];
    vector<int>b(n,0);
    vector<bool>done(n,false);

    int idx=0;
    for(int i=0;i<n;i++) cin >> a[i];

    while(idx<n){
        int mx=0;
        vector<int>tmp;
        for(int i=0;i<n;i++){
            if(done[i]) continue;
            if(a[i]>mx){
                tmp.clear();
                tmp.push_back(i);
                mx=a[i];
            }
            else if(a[i]==mx) tmp.push_back(i);
        }

        if(mx==0) break;
        for(int i: tmp) {done[i]=true; b[idx++]=mx;}
        for(int i=0;i<n;i++) a[i]&=mx;
    }
    
    while(idx<n) b[idx++]=0;

    for(int i=0;i<n;i++) cout << b[i]<<" ";
    cout << endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}