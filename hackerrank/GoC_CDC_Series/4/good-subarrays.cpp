#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+2;
const int INF = 1e7;
int sp[N];
map<int,int>mp;
vector<int>last;

void sieve(){
    for(int i=2;i<N;i++) sp[i]=i;
    
    int idx=0;
    for(int i=2;i<N;i++){
        if(sp[i]==i){
            mp[i]=idx++;
            for(int j=2*i;j<N;j+=i) sp[j] = min(sp[j],i);
        }
    }
    last.resize(idx,INF);
}

int main(){
    sieve();
    
    int n; cin >> n;
    int a[n+1];
    for(int i=1;i<=n;i++) cin >> a[i];
    
    int dp[n+1];
    dp[0]=0;
    
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+1;
        
        int num = a[i];
        while(num>1){
            int p = sp[num];
            int idx = mp[p];
            
            dp[i] = min(dp[i],last[idx]+1);
            last[idx]=min(last[idx],dp[i-1]);
            
            while(num%p==0) num/=p;
        }
    }
    
    cout << dp[n] << endl;
}