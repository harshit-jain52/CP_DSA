#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e6+1;
vector<int>divis[N];

void divisors(){
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            divis[j].push_back(i);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    int a[n];
    map<int,int>ct;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        ct[a[i]]++;
    }

    ll ans = 0;
    for(int i=0;i<n;i++){
        for(auto d: divis[a[i]]){
            int sqr = sqrt(d);
            if(sqr*sqr != d) continue;
            ans += ct[a[i]/d]*1LL*ct[a[i]/sqr];
        }
    }

    for(auto it: ct){
        int x = it.second;
        ans += (1LL*x*(x-1)*(x-2));
    }

    cout << ans << endl;
}

int main()
{
    FASTIO
    divisors();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}