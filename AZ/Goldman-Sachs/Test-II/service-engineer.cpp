#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second

const ll INF = 1e16; 
vector<pii>vec;
int dist[15][15], mat[30][30], sz;
ll dp[15][1<<15];

ll func(int idx, int mask){
    if(__builtin_popcount(mask)==sz) return 0;
    if(dp[idx][mask]!=-1) return dp[idx][mask];

    ll ans = INF;
    for(int i=0;i<sz;i++){
        if((mask>>i)&1) continue;
        ans = min(ans,mat[vec[i].F][vec[i].S]+2*dist[idx][i]+func(i,(mask|(1<<i))));
    }

    return dp[idx][mask]=ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int r,c;
    cin >> r >> c;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> mat[i][j];
            if(mat[i][j]>0) vec.push_back({i,j});
        }
    }

    sz = vec.size();
    for(int i=0;i<sz;i++){
        for(int j=i;j<sz;j++){
            int d = abs(vec[i].F-vec[j].F)+abs(vec[i].S-vec[j].S);
            dist[i][j]=dist[j][i]=d;
        }
    }

    ll hours = INF;
    for(int i=0;i<sz;i++){
        hours = min(hours,mat[vec[i].F][vec[i].S]+func(i,(1<<i)));
    }
    if(sz==0) hours=0;
    cout << (hours+7)/8;
}