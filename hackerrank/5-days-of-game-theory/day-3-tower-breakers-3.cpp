#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;

vector<int> divis[N];
int g[N];

void sieve(){
    for(int i=1;i<N;i++){
        for(int j=2*i;j<N;j+=i){
            divis[j].push_back(i);
        }
    }
}

int mex(set<int>&st){
    int num=0;
    for(int it: st) if(it==num) num++;
    return num;
}

void grundy(){
    for(int i=2;i<N;i++){
        set<int>tmp;
        for(int d: divis[i]){
            if((i/d)&1) tmp.insert(g[d]);
            else tmp.insert(0);
        }
        g[i]=mex(tmp);
    }
}

void solve(){
    int n,x=0;
    cin >> n;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        x^=g[num];
    }
    
    if(x) cout << 1;
    else cout << 2;
    cout << endl;
}

int main(){
    sieve();
    grundy();
    int t; cin >> t;
    while(t--) solve();
}