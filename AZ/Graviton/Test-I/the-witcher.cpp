#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+7;
typedef long long ll;
int sp[N], pct;
vector<int>nxt;
map<int,int> mp;

void sieve(){
    for(int i=2;i<N;i++) sp[i]=i;
    pct=0;

    for(int i=2;i<N;i++){
        if(sp[i]==i){
            mp[i]=pct++;
            for(int j=2*i; j<N; j+=i) sp[j]=min(sp[j],i);
        }
    }
}

void solve(){
    nxt.assign(pct,-1);
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    vector<ll>dp(n,0);
    for(int i=n-1;i>=0;i--){
        dp[i]=1;
        int num = a[i];
        while(num>1){
            int p = sp[num];
            int pos = mp[p];
            if(nxt[pos]!=-1) dp[i]=max(dp[i],1+dp[nxt[pos]]);
            nxt[pos]=i;

            while(num%p==0) num/=p;
        }
    }

    cout << *max_element(dp.begin(),dp.end()) << endl;
}

int main(){
    sieve();
    int t; cin >> t;
    while(t--) solve();
}