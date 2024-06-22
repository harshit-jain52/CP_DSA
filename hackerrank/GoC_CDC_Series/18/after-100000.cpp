#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s;
    cin >> s;
    vector<int>num(n,0);
    
    int lastR=0;
    for(int i=0;i<n;i++){
        if(s[i]=='R') lastR=i;
        else{
            int diff = i-lastR;
            num[lastR + (diff&1)]++;
        }
    }
    
    int lastL=n-1;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='L') lastL = i;
        else{
            int diff = lastL-i;
            num[lastL - (diff&1)]++;
        }
    }
    
    for(int i=0;i<n;i++) cout << num[i] << " ";
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}