#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
const int M = 1e9+7;
const int N = 2e5+5;
int par[N];

int find(int v){
    if(par[v]==v) return v;
    return par[v]=find(par[v]);
}

void Union(int u, int v){
    u = find(u);
    v = find(v);

    if(u==v) return;
    if(u<v) swap(u,v);
    par[v]=u;
}

int main()
{
    FASTIO
    int n,q;
    cin >> n >> q;

    for(int i=1;i<=n+1;i++) par[i]=i;

    vector<int>ans(n+1,0);
    int l[q],r[q],c[q];
    
    for(int i=0;i<q;i++) cin >> l[i]>>r[i]>>c[i];

    for(int i=q-1;i>=0;i--){
        int tmp = find(l[i]);
        while(tmp<=r[i]){
            ans[tmp]=c[i];
            Union(tmp,tmp+1);
            tmp = find(tmp);
        }
    }

    for(int i=1;i<=n;i++) cout << ans[i]<<endl;
}