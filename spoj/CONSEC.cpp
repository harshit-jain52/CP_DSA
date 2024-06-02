#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;
const int N = 2e5+5;
int par[N], set_size[N];

void make(int v){
    par[v]=v;
    set_size[v]=1;
}

int find(int v){
    if(par[v]==v) return v;
    return par[v]=find(par[v]);
}

void Union(int u, int v){
    u = find(u);
    v = find(v);

    if(u==v) return;
    if(set_size[u]<set_size[v]) swap(u,v);
    par[v]=u;
    set_size[u]+=set_size[v];
}

void solve()
{
    int n,Q;
    string s,t;
    cin >> s >> Q;
    n = s.size();
    t = s;
    pii q[Q];
    
    for(int i=0;i<n;i++) make(i);
    vector<int>ans;
    
    for(int i=0;i<Q;i++){
        cin >> q[i].F>>q[i].S;
        if(q[i].F==2) t[q[i].S]='#';
    }

    for(int i=1;i<n;i++){
        if(t[i]=='#') continue;
        if(t[i]==t[i-1]) Union(i,i-1);
    }

    for(int i=Q-1;i>=0;i--){
        int idx = q[i].S;
        if(q[i].F==1){
            ans.push_back(set_size[find(idx)]);
        }
        else{
            t[idx]=s[idx];
            if(idx<n-1 && t[idx]==t[idx+1]) Union(idx,idx+1);
            if(idx>0 && t[idx]==t[idx-1]) Union(idx,idx-1);
        }
    }

    reverse(ans.begin(),ans.end());
    for(int a: ans) cout << a << endl;
}

int main()
{
    FASTIO
    int t; cin >> t;
    for(int i=1;i<=t;i++){
        cout << "Case "<<i<<":\n";
        solve();
    }
}