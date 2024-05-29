#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 3e5+5;
int fact[N];

void solve(){
    int n;
    cin >> n;

    for(int k=1;k<=n;k++){        
        int num = n/k, extra = k-n%k;
        cout << (((fact[num]*1LL*fact[n-num])%M)*1LL*extra)%M<<" ";
    }
    cout << endl;
}

int main()
{
    FASTIO

    fact[0]=1;
    for(int i=1;i<N;i++) fact[i] = (fact[i-1]*1LL*i)%M;

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}