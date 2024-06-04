#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 3e5+5;
int sp[N];

void sieve(){
    for(int i=2;i<N;i++) sp[i]=i;

    for(int i=2;i<N;i++){
        if(sp[i]==i){
            for(int j=2*i;j<N;j+=i){
                sp[j]=min(sp[j],i);
            }
        }
    }
}

int main()
{
    FASTIO
    sieve();

    int n; cin >> n;
    map<int,int>node;
    vector<vector<int>>g(n+1);

    int curr = n;
    for(int i=1;i<=n;i++){
        int a; cin >> a;
        int u=i;
        int num = a;
        while(num>1){
            int d = sp[num];
            if(node.find(d)==node.end()){
                node[d] = ++curr;
                g.push_back(vector<int>());
            }
            int v = node[d];
            g[u].push_back(v);
            g[v].push_back(u);

            while(num%d==0) num/=d;
        }
    }

    int s,t; cin >> s >> t;

    int par[curr+1];
    vector<bool>vis(curr+1,false);
    queue<int>q;

    par[s]=-1;
    q.push(s);
    vis[s]=true;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        if(v==t) break;

        for(int ch: g[v]){
            if(vis[ch]) continue;
            par[ch]=v;
            vis[ch]=true;
            q.push(ch);
        }
    }

    if(!vis[t]) cout << -1;
    else{
        vector<int>path;
        int c = t;
        while(c!=-1){
            path.push_back(c);
            c = par[c];
        }

        reverse(path.begin(),path.end());
        cout << (path.size()+1)/2 << endl;
        for(int i=0;i<path.size();i++){
            if((i&1)==0) cout << path[i]<<" ";
        }
    }
}