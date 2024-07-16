#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k; cin >> n >> k;
    int a[n];
    bool flag = false;

    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i]==1 && i>0 && a[i-1]==1) flag = true;
    }

    if(flag){
        cout << "NO\n";
        return;
    }
    
    for(int i=0;i<n;){
        if(a[i]==1) i+=2;
        else if((i==0 || a[i-1]!=1) && (i==n-1 || a[i+1]!=1)){
            k--;
            i+=2;
        }
        else i++;
    }

    if(k>0) cout << "NO\n";
    else cout << "YES\n";
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}