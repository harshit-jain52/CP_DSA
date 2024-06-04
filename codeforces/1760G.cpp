#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
#define F first
#define S second
const int M = 1e9+7;


void solve(){
    int n,a,b;
    cin >> n>>a>>b;

    vector<vector<pii>>g(n+1);
    vector<bool>vis;

    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

   int xora[n+1],xorb[n+1];
   xora[a]=0; xorb[b]=0; 
   queue<int>q;
   vis.assign(n+1,false);

   q.push(a);
   vis[a]=true;

   set<int>st;
   st.insert(0);
   bool ans = false;    
   while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto ch: g[cur]){
            if(vis[ch.F]) continue;
            xora[ch.F] = xora[cur]^ch.S;
            if(ch.F==b) continue;
            st.insert(xora[ch.F]);
            q.push(ch.F);
            vis[ch.F]=true;
        }
   }

   vis.assign(n+1,false);
   q.push(b);
   vis[b]=true;
   while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto ch: g[cur]){
            if(vis[ch.F]) continue;
            xorb[ch.F] = xorb[cur]^ch.S;
            ans |= (st.find(xorb[ch.F])!=st.end());
            q.push(ch.F);
            vis[ch.F]=true;
        }
   }

   if(ans) cout << "YES\n";
   else cout << "NO\n";
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