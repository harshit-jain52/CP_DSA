#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    int n; cin >> n;
    ll a[n];

    ll tot = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        tot += (n-1)*a[i];
    }

    const int LIM = 1e8;
    sort(a,a+n);

    for(int i=0;i<n;i++){
        int x = (lower_bound(a,a+n,LIM-a[i]) - a);
        x=max(x,i+1);
        tot -= (n-x)*1LL*LIM;
    }
    cout << tot;
}