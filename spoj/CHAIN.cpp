#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 5e4+4;

vector<pair<int,int>>par(N);

pair<int,int> find(int v){
    if(v!=par[v].first){
        int len = par[v].second;
        par[v] = find(par[v].first);
        par[v].second+=len;
        par[v].second%=3;
    }
    return par[v];
}

void solve(){
    int n,k; cin >> n >> k;
    for(int i=0;i<=n;i++) par[i]=make_pair(i,0);

    int ct = 0;
    while(k--){
        int d,x,y;
        cin >> d >>x >> y;
        d--;
        if(x>n || y>n){
            ct++; continue;
        }

        auto px = find(x), py = find(y);
        int diff = (py.second-px.second+3)%3;

        if(px.first==py.first){
            if(d != diff) ct++;
        }
        else{
            par[py.first] = {px.first,(3-diff+d)%3};
        }
        
    }
    cout << ct << endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
