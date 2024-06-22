#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
#define F first
#define S second

int main()
{
    FASTIO
    int n; cin >> n;
    priority_queue<pair<ll,int>>pq;
    ll sum = 0;
    for(int i=0;i<n;i++){
        ll a; cin >> a;
        sum += a;
        pq.push({-3*a,3});
    }

    int ct = n-2;
    while(ct--){
        auto cur = pq.top();
        pq.pop();
        sum += (-cur.F);
        pq.push({(cur.F/cur.S)*(cur.S+2),cur.S+2});
    }

    cout << sum;
}