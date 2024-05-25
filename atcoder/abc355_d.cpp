#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
typedef long long ll;
const int INF = 1e9;

int main()
{
    FASTIO
    int n;
    cin >> n;

    vector<pair<int,int>>vec(n);
    for(int i=0;i<n;i++){
        cin >> vec[i].F >> vec[i].S;
    }

    sort(vec.begin(),vec.end());

    ll ct = 0;
    for(int i=0; i<n; i++){
        int l = vec[i].F, r = vec[i].S;
        int idx = upper_bound(vec.begin(),vec.end(),make_pair(r,INF)) - vec.begin();
        // cout << i<<" "<<idx<<endl;
        ct += (idx-i-1);
    }

    cout << ct;
}