#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,x=0;
    bool all1=true;
    cin >> n;
    for(int i=0;i<n;i++){
        int s; cin >> s;
        all1 &= (s==1);
        x^=s;
    }
    
    if(all1) x = 1 - n%2;
    if(x==0) cout << "Second";
    else cout << "First";
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}