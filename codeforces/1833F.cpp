#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int binpow(int a, int b){
    int ans = 1;
    while(b){
        if(b&1) ans = (ans*1LL*a)%M;
        a = (a*1LL*a)%M;
        b>>=1;
    }
    return ans;
}


void solve(){
    int n,m;
    cin >> n >> m;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        mp[a]++;
    }

    vector<int>vec;
    vector<int>prod; prod.push_back(1);

    for(auto it: mp){
        vec.push_back(it.first);
        prod.push_back((prod.back()*1LL*it.second)%M);
    }

    int ans = 0;
    for(int i=m-1;i<vec.size();i++){
        if(vec[i-m+1]==vec[i]-m+1){
            ans = (ans + (prod[i+1]*1LL*binpow(prod[i-m+1],M-2))%M)%M;
        }
    }
    cout << ans << endl;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}