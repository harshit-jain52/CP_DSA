#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
ll k, a[20][20];
map<ll,ll>ct[20][20];
ll ans = 0;

void dfs1(int x, int y, ll mod){
    if((x+y)==(n+m)/2){
        ct[x][y][(mod+a[x][y])%k]++;
        return;
    }
    if(x<n) dfs1(x+1,y,(mod+a[x][y])%k);
    if(y<m) dfs1(x,y+1,(mod+a[x][y])%k);
}

void dfs2(int x, int y, ll mod){
    if((x+y)==(n+m)/2){
        ll req = (k-mod)%k;
        ans += ct[x][y][req];
        return;
    }
    
    if(x>1) dfs2(x-1,y,(mod+a[x][y])%k);
    if(y>1) dfs2(x,y-1,(mod+a[x][y])%k);
}

int main(){
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];
    
    dfs1(1,1,0);
    dfs2(n,m,0);
    
    cout << ans;
}