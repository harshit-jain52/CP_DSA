#include <bits/stdc++.h>
using namespace std;

int dp[20][59050];
int pow3[10], arr[20];
int n,k;
int getTern(vector<int>&num){
    int ans = 0;
    for(int i=0;i<k;i++){
        ans += num[i]*pow3[i];
    }
    return ans;
}

int func(int idx, vector<int>&num){
    if(idx==n) return 0;
    int mask = getTern(num);
    if(dp[idx][mask]!=-1) return dp[idx][mask];
    
    int ans = 0;
    for(int i=1;i<=k;i++){
        if(num[i-1]<2){
            num[i-1]++;
            ans = max(ans, (arr[idx]&i) + func(idx+1,num));
            num[i-1]--;
        }
    }
    
    return dp[idx][mask] = ans;
}

int main(){
    memset(dp,-1,sizeof(dp)); 
    pow3[0]=1;
    for(int i=1;i<10;i++) pow3[i]=3*pow3[i-1];
    
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> arr[i];
    vector<int>num(k,0);
    cout << func(0,num);
}