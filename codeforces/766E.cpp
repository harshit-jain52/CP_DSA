#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

int n;
vector<int> g[N];
int a[N], subsz[N], indp[N][20], outdp[N][20];

void indfs(int v, int pp){
    subsz[v]=1;
    for(int bit=0;bit<20;bit++){
        indp[v][bit] = (a[v]>>bit)&1;
    }

    for(int ch: g[v]){
        if(ch==pp) continue;
        indfs(ch,v);

        subsz[v]+=subsz[ch];
        for(int bit=0;bit<20;bit++){
            if((a[v]>>bit)&1) indp[v][bit] += subsz[ch]-indp[ch][bit];
            else indp[v][bit] += indp[ch][bit];
        }
    }
}

void outdfs(int v, int pp){
    // for(int bit=0;bit<20;bit++){
    //     outdp[v][bit] += (a[v]>>bit)&1;
    // }    

    for(int ch: g[v]){
        if(ch==pp) continue;
        for(int bit=0;bit<20;bit++){
            int all = outdp[v][bit]+indp[v][bit];

            if((a[v]>>bit)&1) all -= subsz[ch]-indp[ch][bit];
            else all -= indp[ch][bit];

            if((a[ch]>>bit)&1) outdp[ch][bit] += n-subsz[ch]-all;
            else outdp[ch][bit] += all;
        }
        outdfs(ch,v);
    }
}

int main()
{
    FASTIO
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    indfs(1,0);
    outdfs(1,0);

    ll tot = 0;
    for(int i=1;i<=n;i++){
        for(int bit=0;bit<20;bit++){
            tot += (1LL<<bit)*(indp[i][bit]+outdp[i][bit]);
            tot += (1LL<<bit)*((a[i]>>bit)&1);
        }
    }

    cout << tot/2;
}