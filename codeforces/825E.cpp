#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin >> n >> m;
    vector<vector<int>>rg(n+1);
    vector<int>outdeg(n+1,0);
    vector<int>label(n+1);

    while(m--){
        int v,u; cin >> v >> u;
        rg[u].push_back(v);
        outdeg[v]++;
    }

    priority_queue<int> pq;
    for(int i=1;i<=n;i++) if(outdeg[i]==0) pq.push(i);

    int num=n;

    while(!pq.empty()){
        int v = pq.top();
        pq.pop();
        label[v]=num--;
        for(int ch: rg[v]){
            outdeg[ch]--;
            if(outdeg[ch]==0) pq.push(ch);
        }
    }

    for(int i=1;i<=n;i++) cout << label[i]<<" ";
}