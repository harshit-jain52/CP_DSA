#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 5e4+1;

vector<int>g[N];
int indp[N][501],outdp[N][501];
int k;

void indfs(int v, int pp){
    indp[v][0]=1;

    for(int ch: g[v]){
        if(ch==pp) continue;
        indfs(ch,v);

        for(int i=1;i<=k;i++) indp[v][i] += indp[ch][i-1];
    }
}

void outdfs(int v, int pp){
    for(int ch: g[v]){
        if(ch==pp) continue;

        for(int i=1;i<=k;i++){
            outdp[ch][i] = outdp[v][i-1] + indp[v][i-1];
            if(i>=2) outdp[ch][i]-=indp[ch][i-2];
        }

        outdfs(ch,v);
    }
}

int main()
{
    FASTIO
    int n;
    cin >> n >> k;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    indfs(1,0);
    outdfs(1,0);

    ll num=0;
    for(int i=1;i<=n;i++) num += indp[i][k] + outdp[i][k];

    cout << num/2;
}