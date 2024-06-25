#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int ct0=0,ct1=0,ct2=0;
    int y0=0,y1=0,y2=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int a; cin >> a;
            ct0 += (a==0);
            ct1 += (a==1);
            ct2 += (a==2);
            
            if((i<n/2 && (j==i || j==n-1-i)) || (i>=n/2 && j==n/2)){
                y0 += (a==0);
                y1 += (a==1);
                y2 += (a==2);
            }
        }
    }
    
    cout << min({y1+y2+ct0-y0+min(ct1-y1,ct2-y2),y0+y2+ct1-y1+min(ct0-y0,ct2-y2),y1+y0+ct2-y2+min(ct1-y1,ct0-y0)}) << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}