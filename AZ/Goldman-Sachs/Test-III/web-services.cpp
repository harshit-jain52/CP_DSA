#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
#define F first
#define S second
const ll INF = 1e15;

struct Dep{
    int x, y, wt;
    Dep(){}
};

void solve(){
    int n,d,a; cin >> n >> d >> a;
    
    vector<Dep>edg(d);
    for(int i=0;i<d;i++){
        cin >> edg[i].x >> edg[i].y >> edg[i].wt;
    }

    vector<ll>dist(n+1,INF);
    dist[a]=0;

    for(int _=0;_<n-1;_++){
        for(int i=0;i<d;i++){
            if(dist[edg[i].y]!=INF){
                dist[edg[i].x] = min(dist[edg[i].x],dist[edg[i].y]+edg[i].wt);
            }
        }
    }

    int ct=0;
    ll mint=0;

    for(int i=1;i<=n;i++){
        if(dist[i]!=INF){
            ct++;
            mint = max(mint,dist[i]);
        }
    }

    cout << ct << " " << mint << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}