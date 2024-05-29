#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,x=0;
    cin >> n;
    for(int i=0;i<n;i++){
        int s; cin >> s;
        x^=s;
    }
    
    if(x==0) cout << "Second";
    else cout << "First";
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}