#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int sum=0;
    ll add =0;
    map<int,ll>mp;
    mp[0]++;
    for(int i=0;i<n;i++){
        int num = (s[i]=='1')?1:-1;
        sum+=num;
        add+=mp[sum];
        mp[sum]++;
    }

    ll tot = (n*1LL*(n+1))/2 + add;
    cout << tot<<endl;
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