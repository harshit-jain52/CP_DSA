#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
    int l,r;
    cin >> l >> r;
    int bit=0;
    while((1<<bit)<=r) bit++;

    cout << bit-1<<endl;
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