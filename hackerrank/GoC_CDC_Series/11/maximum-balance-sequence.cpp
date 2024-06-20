#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x; cin >> n >> x;
    int a[n], tot=0;
    for(int i=0;i<n;i++){
        int tmp; cin >> tmp;
        if(tmp>x) a[i]=1;
        else if(tmp<x) a[i]=-1;
        else a[i]=0;
        
        tot += a[i];
    }
    
    if(tot==0){
        cout << n;
        return 0;
    }
    
    int req = tot;
    int len = n;
    
    map<int,int>mp;
    mp[0]=-1;
    int pref=0;
    for(int i=0;i<n;i++){
        pref += a[i];
        if(mp.find(pref-req)!=mp.end()) len = min(len,i-mp[pref-req]);
        mp[pref]=i;
    }
    
    cout << n-len;
}
