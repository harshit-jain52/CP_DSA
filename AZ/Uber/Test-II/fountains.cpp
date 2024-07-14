#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef pair<int,int> pii;
#define F first
#define S second

int func(vector<pii>vec, priority_queue<pii>pq, int lim){
    int ans=0, idx=0, sz=vec.size();
    priority_queue<int>aux;
    for(int num=0;num<=lim;num++){
        int num2 = lim-num;
        while(idx<sz && vec[idx].F<=num){
            aux.push(vec[idx++].S);
            while(!pq.empty() && (pq.top().S<idx || vec[pq.top().S].F>num2)) pq.pop();
            if(!pq.empty()) ans = max(ans,aux.top()+pq.top().F);
        }
    }
    return ans;
}

void solve(){
        
    int N, C, D;
    cin >> N >> C >> D;
    
    vector<pii>coin, diam;
    priority_queue<pii>pqc, pqd;
    
    for(int i=0;i<N;i++){
        int b,p;
        char curr;
        cin >> b >> p >> curr;
        if(curr=='C') coin.push_back({p,b});
        else diam.push_back({p,b});
    }
     
    sort(coin.begin(),coin.end());
    sort(diam.begin(),diam.end());
    for(int i=0;i<(int)coin.size();i++) pqc.push({coin[i].S,i});
    for(int i=0;i<(int)diam.size();i++) pqd.push({diam[i].S,i});
    
    int ans1 = func(coin,pqc,C); // both by coins
    int ans2 = func(diam,pqd,D); // both by diamonds
    
    // use both currency
    int ans3 = 0;
    while(!pqc.empty() && coin[pqc.top().S].F>C) pqc.pop();
    while(!pqd.empty() && diam[pqd.top().S].F>D) pqd.pop();
    
    if(!pqc.empty() && !pqd.empty()) ans3 = pqc.top().F + pqd.top().F;
    
    cout << max({ans1,ans2,ans3}) << endl;
}

int main(){
    FASTIO

    int t; cin >> t;
    while(t--) solve();
}