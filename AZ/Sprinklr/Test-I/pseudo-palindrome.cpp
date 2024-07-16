#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int n=s.size();

    int mask=0;
    map<int,int>mp;
    mp[0]++;

    long long ans = 0;
    for(int i=0;i<n;i++){
        int d = s[i]-'a';
        mask ^= (1<<d);

        ans += mp[mask];
        for(int bit=0;bit<18;bit++) ans += mp[mask^(1<<bit)];

        mp[mask]++;
    }

    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}