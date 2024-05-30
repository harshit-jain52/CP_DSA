#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
vector<int> g[N];
bool taken[N];

int main(){
    int n,m;
    cin >> n >> m;
    int a[m],b[m];
    for(int i=0;i<m;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    for(int i=0;i<m;i++){
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    
    ll ct = 0;
    int head=0,tail=1;
    
    auto check = [&](int num)->bool{
        for(int e: g[num]) if(taken[e]) return false;
        return true;
    };
    
    while(tail<=n){
        while(head+1<=n && check(head+1)){
            head++;
            taken[head]=true;
        }
        ct += (head-tail+1);
        if(head>=tail){
            taken[tail]=false;
            tail++;
        }
        else{
            tail++;
            head=tail-1;
        }
    }
    
    cout << ct;
}