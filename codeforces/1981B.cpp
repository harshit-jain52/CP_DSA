#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
    int n,m;
    cin >> n >> m;

    // OR of (n-m)|(n-m+1)....(n-1)|n|(n+1)|.....(n+m-1)|(n+m)

    int l=max(0,n-m),r = n+m;

    int diff=r-l;
    int bit=0;
    while((1LL<<bit)<=diff) bit++;
    int ans = (1LL<<bit)-1;

    cout << (l|ans|r) << endl;

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