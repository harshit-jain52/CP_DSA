#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    int n; cin >> n;
    vector<int>g[n+1];
    for(int i=0;i<n-1;i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int pos[n+1], a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        pos[a[i]] = i;
    }

    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end(),[&](int x, int y)->bool{
            return pos[x]<pos[y];
        });
    }

    vector<int>ans;
    vector<bool>vis(n+1,false);
    queue<int>q;
    q.push(1);
    vis[1]=true;
    ans.push_back(1);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int ch: g[v]){
            if(!vis[ch]){
                q.push(ch);
                vis[ch]=true;
                ans.push_back(ch);
            }
        }
    }

    bool flag = true;
    for(int i=0;i<n;i++) flag &= (a[i]==ans[i]);

    cout << (flag?"Yes":"No");
}