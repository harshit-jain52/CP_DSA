#include <bits/stdc++.h>
using namespace std;

int dp[16][16];
int g[16][16];

int mex(set<int>&st){
    int num=0;
    for(int it: st) if(num==it) num++;
    return num;
}

void grundy(){
    for(int sum=2;sum<=30;sum++){
        for(int x=1;x<min(16,sum);x++){
            int y = sum-x;
            if(y>15) continue;
            set<int>tmp;
            if(x>2 && y<15) tmp.insert(g[x-2][y+1]);
            if(x>2 && y>1) tmp.insert(g[x-2][y-1]);
            if(x<15 && y>2) tmp.insert(g[x+1][y-2]);
            if(x>1 && y>2) tmp.insert(g[x-1][y-2]);
            g[x][y]=mex(tmp);
        }
    }
}

void solve(){
    int k; cin >> k;
    int res=0;
    while(k--){
        int x,y;
        cin >> x >> y;
        res ^= g[x][y];
    }
    
    if(res) cout << "First";
    else cout << "Second";
    cout << endl;
}

int main(){
    grundy();
    int t; cin >> t;
    while(t--) solve();
}