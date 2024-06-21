#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
typedef long long ll;
const int M = 1e9+7;
const int N = 1e6+2;
const ll INF = 1e15;
int n,m;
int sp[N], uni[N];
vector<pair<int,int>>steps={{1,1},{1,-1},{-1,1},{-1,-1}};

void smallestPrimeFactor()
{
    for (int i = 2; i < N; i++)
        sp[i] = i;

    for (int i = 2; i < N; i++)
    {
        if (sp[i] == i)
            for (int j = 2 * i; j < N; j += i)
                sp[j] = min(sp[j], i);
    }
}

void primeFact(int num)
{   
    int orig=num;
    while (num > 1)
    {
        int pf = sp[num];
        while(num%pf==0) num/=pf;
        uni[orig]++;
    }
}

inline bool check(int x,int y){
    return (x>0 && y>0 && x<=n && y<=m);
}

int main()
{
    FASTIO
    smallestPrimeFactor();
    int mx=-1;
    for(int i=2;i<N;i++){
        primeFact(i);
        mx=max(mx,uni[i]);
    }
    uni[1]=0;
    // cout << mx; // comes out to be 7
    
    cin >> n >> m;
    vector<vector<ll>>dist(n+1,vector<ll>(m+1,INF));
    int a[n+1][m+1];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }

    dist[1][1]=0;
    priority_queue<pair<ll,pair<int,int>>>pq;
    pq.push({0,{1,1}});

    while(!pq.empty()){
        auto v = pq.top();
        pq.pop();
        int x=v.S.F,y=v.S.S;
        ll wt = sqrt(a[x][y]);
        int p = uni[a[x][y]];
        for(int dx=0;dx<=p;dx++){
            for(int dy=p-dx;dy>=0;dy--){
                if(dx==0 && dy==0) continue;
                for(auto st: steps){
                    int nx=x+dx*st.F, ny=y+dy*st.S;
                    if(!check(nx,ny)) continue;
                    if(dist[nx][ny]>dist[x][y]+wt){
                        dist[nx][ny]=dist[x][y]+wt;
                        pq.push({-dist[nx][ny],{nx,ny}});
                    }
                }
            }
        }
    }

    cout << ((dist[n][m]<INF)?dist[n][m]:-1);
}