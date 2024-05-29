#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+1;

int sp[N];
void sieve(){
    for(int i=2;i<N;i++) sp[i]=i;
    
    for(int i=2;i<N;i++){
        if(sp[i]==i){
            for(int j=2*i;j<N;j+=i) sp[j] = min(sp[j],i);
        }
    }
}

void solve(){
    int n,x=0;
    cin >> n;
    for(int i=0;i<n;i++){
        int num,ct=0;
        cin >> num;
        while(num>1){
            num/=sp[num];
            ct++;
        }
        x ^= ct;
    }
    
    if(x) cout << 1;
    else cout << 2;
    cout << endl;
}

int main(){
    sieve();
    int t; cin >> t;
    while(t--) solve();
}