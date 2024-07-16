#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s; cin >> s;
    int n=s.size();

    int mask=0;
    map<ll,int>mp;
    mp[0]++;

    ll ans = 0;
    for(int i=0;i<n;i++){
        int d = s[i]-'a';
        mask ^= (1<<d);

        ans += mp[mask];
        for(int bit=0;bit<26;bit++) ans += mp[mask^(1<<bit)];

        mp[mask]++;
    }

    cout << ans << endl;
}