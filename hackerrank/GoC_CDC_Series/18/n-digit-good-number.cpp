#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int dp[1001][9001];
int ans[1001][10][10];
vector<bool>dig(10);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(dp,0,sizeof(dp));
    memset(ans,0,sizeof(ans));
    
    dp[0][0]=1;
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=9*i;j++){
            for(int d=0;d<=9;d++){
                if(j>=d){
                    dp[i][j] += dp[i-1][j-d];
                    dp[i][j]%=M;
                }
                dig[d]=false;
            }
            
            int num = j;
            while(num){
                dig[num%10]=true;
                num/=10;
            }
            
            int ct=0;
            int d1=-1,d2=-1;
            for(int d=0;d<=9;d++){
                if(dig[d]){
                    if(d1==-1) d1=d;
                    d2=d;
                    ++ct;    
                }
            }
            if(ct<=2){
                ans[i][d1][d2] += dp[i][j];
                ans[i][d1][d2]%=M;
            }
        }
    }

    int t; cin >> t;
    while(t--){
        int n,x,y; cin >> n >> x >> y;
        if(x>y) swap(x,y);
        cout << (ans[n][x][y] + (ans[n][x][x] + ans[n][y][y])%M)%M << '\n';
    }
}