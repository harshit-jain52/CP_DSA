#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
const int M = 1e9+7;

vector<bool> isPrime(N,true);
int tot,with2,rem;

void sieve(){
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<N;i++){
        if(isPrime[i]){
            for(int j=2*i;j<N;j+=i) isPrime[j]=false;
        }
    }
}

void count(){
    tot=0; with2=0;
    for(int i=2;i<N;i++){
        if(isPrime[i]){
            tot++;
            if(i+2<N && isPrime[i+2]) with2++;
        }
    }
    rem = tot-with2;
}

vector<int>g[N];
int dp[N][2][2];

int dfs(int v, int pp, bool last2, bool can2){
    int ans = 0;
    
    if(dp[v][last2][can2]!=-1) return dp[v][last2][can2];
    
    if(last2){        
        int tmp1=rem-1;
        for(int ch: g[v]) if(ch!=pp) tmp1 = (tmp1*1LL*dfs(ch,v,0,1))%M;
        int tmp2=1;
        for(int ch: g[v]) if(ch!=pp) tmp2 = (tmp2*1LL*dfs(ch,v,1,1))%M;
        
        ans = (tmp1+tmp2)%M;
    }
    else{
        int tmp1 = rem-1;
        for(int ch: g[v]) if(ch!=pp) tmp1 = (tmp1*1LL*dfs(ch,v,0,1))%M;
        
        int tmp2=0;
        if(can2){
            tmp2=1;
            for(int ch: g[v]) if(ch!=pp) tmp2 = (tmp2*1LL*dfs(ch,v,1,1))%M;
        }
        
        int tmp3=with2;
        for(int ch: g[v]) if(ch!=pp) tmp3 = (tmp3*1LL*dfs(ch,v,0,0))%M;
        
        ans = ((tmp1+tmp2)%M + tmp3)%M;
    }
    
    return dp[v][last2][can2]=ans;
}

void solve(){
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        g[i].clear();
        dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=-1;
    }
    
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    cout << dfs(1,0,0,1)<< endl;
}
int main(){
    sieve();
    count();
    int t; cin >> t;
    while(t--) solve();
}