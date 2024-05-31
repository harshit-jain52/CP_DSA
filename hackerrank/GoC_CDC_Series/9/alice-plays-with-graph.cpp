#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

pair<int,int> parent[N];
int set_size[N];
bool isBipartite;

void make(int v) {
    parent[v] = make_pair(v, 0);
    set_size[v] = 1;
}

pair<int, int> find(int v) {
    if (v != parent[v].first) {
        int parity = parent[v].second;
        parent[v] = find(parent[v].first);
        parent[v].second ^= parity;
    }
    return parent[v];
}

void add(int a, int b) {
    pair<int, int> pa = find(a);
    a = pa.first;
    int x = pa.second;

    pair<int, int> pb = find(b);
    b = pb.first;
    int y = pb.second;

    if (a == b) {
        if (x == y)
            isBipartite=false;
    } else {
        if (set_size[a] < set_size[b])
            swap (a, b);
        parent[b] = make_pair(a, x^y^1);
        set_size[a]+=set_size[b];
    }
}

void reset(int n){
    isBipartite=true;
    for(int i=1;i<=n;i++) make(i);
}

void solve(){
    int n,m;
    cin >> n >> m;
    reset(n);
    int num=0;

    while(m--){
        int u,v;
        cin >> u >> v;
        if(isBipartite) add(u,v);
        if(isBipartite) num++;
    }

    cout << num <<endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}