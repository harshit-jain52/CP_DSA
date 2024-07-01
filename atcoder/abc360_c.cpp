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
    priority_queue<ll>box[n+1];


    int a[n],w[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        cin >> w[i];
        box[a[i]].push(-w[i]);
    }

    ll ans = 0;
    for(int i=1;i<=n;i++){
        while(box[i].size()>1){
            ans -= box[i].top();
            box[i].pop();
        }
    }

    cout << ans;
}