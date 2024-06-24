#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n], minrt[n];
    for(int i=0;i<n;i++) cin >> a[i];
    
    minrt[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--) minrt[i]=min(a[i],minrt[i+1]);
    
    int currmx = 0;
    int k = 0;
    for(int i=0;i<n;i++){
        currmx = max(currmx,a[i]);
        if(i==n-1 || currmx<=minrt[i+1]){
            k++;
            currmx=0;
        }
    }
    
    cout << k << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}