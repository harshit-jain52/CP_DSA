#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 5e5+1;
int a[N];
int n,m;

int check(int num){
    vector<int>vec;
    for(int i=0;i<n;i++) if(i!=num) vec.push_back(a[i]);
    sort(vec.begin(),vec.end());
    if(num<n){    
        int curr = a[num];
        for(int i=0;i<num-1;i++) curr+=vec[i];
        if(curr<=m) return (n-num);
        vec.push_back(a[num]);
    }
    sort(vec.begin(),vec.end());
    int curr=0;
    for(int i=0;i<num;i++) curr+=vec[i];
    if(curr<=m) return (n-num+1);
    return n+1;
}

void solve(){
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];

    int rank = n+1;
    int lo=1,hi=n,mid;
    while(lo<=hi){
        mid = (lo+hi)/2;
        int r = check(mid);
        if(r<n+1){
            rank = min(rank,r);
            lo=mid+1;
        }
        else hi=mid-1;
    }
    cout << rank << endl;
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