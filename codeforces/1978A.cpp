#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    cout << a[n-1] + *max_element(a,a+n-1)<<endl;
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