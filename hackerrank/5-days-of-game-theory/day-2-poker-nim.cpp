#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k,x=0;
    cin >> n>>k;
    for(int i=0;i<n;i++){
        int c; cin >> c;
        x^=c;
    }
    
    if(x==0) cout << "Second";
    else cout << "First";
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}