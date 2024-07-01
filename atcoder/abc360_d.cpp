#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    int n; ll t; cin >> n >> t;

    string s; cin >> s;
    vector<ll>rmove, lmove;

    for(int i=0;i<n;i++){
        ll x; cin >> x;
        if(s[i]=='0') lmove.push_back(x);
        else rmove.push_back(x);
    }

    if(rmove.empty() || lmove.empty()){
        cout << 0;
        return 0;
    }

    sort(lmove.begin(),lmove.end());
    ll ct = 0;
    for(auto x: rmove){
        auto it1 = upper_bound(lmove.begin(),lmove.end(),x+2*t);
        auto it2 = upper_bound(lmove.begin(),lmove.end(),x);
        ct += (it1-it2);
    }

    cout << ct;
}