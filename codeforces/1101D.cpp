#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+1;
int sp[N];
vector<int>pf[N];

void sieve(){
    for(int i=2;i<N;i++) sp[i]=i;

    for(int i=2;i<N;i++){
        if(sp[i]==i){
            for(int j=2*i;j<N;j+=i){
                sp[j] = min(sp[j],i);
            }
        }
    }
}

int a[N];
vector<int>g[N];
vector<int>indp1[N],indp2[N],outdp[N];

void indfs(int v, int pp){
    for(int ch: g[v]){
        if(ch==pp) continue;
        indfs(ch,v);

        for(int i=0;i<pf[a[v]].size();i++){
            for(int j=0;j<pf[a[ch]].size();j++){
                if(pf[a[v]][i] == pf[a[ch]][j]){
                    int tmp = 1+indp1[ch][j];
                    if(tmp>indp1[v][i]){
                        indp2[v][i] = indp1[v][i];
                        indp1[v][i] = tmp;
                    }
                    else if(tmp > indp2[v][i]){
                        indp2[v][i] = tmp;
                    }
                }
            }
        }
    }
}

void outdfs(int v, int pp){   
    for(int ch: g[v]){
        if(ch==pp) continue;

        for(int i=0;i<pf[a[v]].size();i++){
            for(int j=0;j<pf[a[ch]].size();j++){
                if(pf[a[v]][i] == pf[a[ch]][j]){
                    outdp[ch][j] = max(outdp[ch][j],1+outdp[v][i]);
                    if(indp1[ch][j]+1 == indp1[v][i]) outdp[ch][j]=max(outdp[ch][j],indp2[v][i]);
                    else outdp[ch][j]=max(outdp[ch][j],indp1[v][i]);
                }
            }
        }
        outdfs(ch,v);
    }
    indp2[v].clear();
}

int main()
{
    FASTIO
    sieve();
    
    int n;
    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >> a[i];

        int num = a[i];
        vector<int>pftmp;
        while(num>1){
            int p = sp[num];
            pftmp.push_back(p);
            while(num%p==0) num/=p;
        }
        pf[a[i]]=pftmp;
        indp1[i].assign(pftmp.size(),1);
        indp2[i].assign(pftmp.size(),1);
        outdp[i].assign(pftmp.size(),0);
    };

    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    indfs(1,0);
    outdfs(1,0);

    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int p=0;p<pf[a[i]].size();p++) ans = max(ans,indp1[i][p]+outdp[i][p]);
    }

    cout << ans;
}