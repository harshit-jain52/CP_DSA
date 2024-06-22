#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k; cin >> n >> k;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        string p; cin >> p;
        vec[i] = p.length();
    }
    
    string pw; cin >> pw;
    int pwlen = pw.length();
    
    sort(vec.begin(),vec.end());
    int first=-1,last=-1;
    
    for(int i=0;i<n;i++){
        if(vec[i]==pwlen){
            if(first==-1) first = i;
            last = i;
        }
    }
    
    cout << 1+first+5*(first/k) << " "<< 1+last+5*(last/k) << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
}