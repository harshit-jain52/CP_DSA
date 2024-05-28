#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

vector<pair<int,int>>g[N];
bool isBridge[5*N];
int comp[N];
int tin[N],lo[N],timer;

void dfs1(int cur, int par){
    tin[cur]=lo[cur]= ++timer;

    for(auto child:g[cur]){
        int ch = child.first, id = child.second;
        if(ch==par) continue;

        if(tin[ch]) lo[cur]=min(lo[cur],tin[ch]);
        else{
            dfs1(ch,cur);
            if(lo[ch]>tin[cur]) isBridge[id]=true;
            lo[cur]=min(lo[cur],lo[ch]);
        }
    }
}

void dfs2(int cur, int num){
    comp[cur]=num;
    for(auto child:g[cur]){
        int ch = child.first, id = child.second;
        if(comp[ch] || isBridge[id]) continue;
        dfs2(ch,num);
    }
}

int main()
{
    FASTIO
    cout << fixed<<setprecision(5);
    int n,m;
    cin >> n >> m;

    for(int i=1;i<=m;i++){
        int a,b;
        cin >>a >> b;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }

    dfs1(1,0);

    int cp=0;
    for(int i=1;i<=n;i++) if(!comp[i]) dfs2(i,++cp);

    vector<int>ct(cp+1,0);
    for(int i=1;i<=n;i++) ct[comp[i]]++;

    ll numer = 0, all = (n*1LL*(n-1));
    for(int i=1;i<=cp;i++) numer += ct[i]*1LL*(n-ct[i]);

    cout << (double)numer/all;
}