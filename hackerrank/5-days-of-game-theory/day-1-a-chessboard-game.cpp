#include <bits/stdc++.h>
using namespace std;

int dp[16][16];

int func(int x, int y){
    if(x<=0 || y<=0 || x>15 || y>15) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    
    int ans = 0;
    if(x>2 && y<15) ans |= !func(x-2,y+1);
    if(x>2 && y>1) ans |= !func(x-2,y-1);
    if(x<15 && y>2) ans |= !func(x+1,y-2);
    if(x>1 && y>2) ans |= !func(x-1,y-2);
    
    return dp[x][y]=ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int t; cin >> t;
    while(t--){
        int x,y;
        cin >> x>>y;
        if(func(x,y)) cout <<"First";
        else cout << "Second";
        cout << endl;
    }
}