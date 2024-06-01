#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 998244353;

int main()
{
    FASTIO
    ll n,m;
    cin >> n >> m;

    ll ct = 0;
    for(int bit=0;(1LL<<bit)<=m;bit++){
        if(!((m>>bit)&1)) continue;

        ll tmp = (1LL<<(bit+1));
        ll x = n/tmp;
        ll rem = n%tmp;
        ll extra = 0;
        if(rem>=tmp/2) extra = rem-tmp/2+1;
        ct = (ct + ((tmp/2)*x)%M + extra)%M;
    }

    cout << ct;
}