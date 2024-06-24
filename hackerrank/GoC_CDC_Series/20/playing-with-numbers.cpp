#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    
    sort(a,a+n);
    int deno=(n-1)/2;
    int i=0,j=deno;
    for(int k=1;k<=n;k++){
        if(k==1 || k%2==0) cout << a[j++] <<" ";
        else cout << a[i++]<<" ";
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}