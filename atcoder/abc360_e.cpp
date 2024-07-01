#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 998244353;

int binpow(int a, int b){
    int ans = 1;
    while(b){
        if(b&1) ans = (ans*1LL*a)%M;
        a = (a*1LL*a)%M;
        b>>=1;
    }
    return ans;
}

int main()
{
    FASTIO
    int n,k; cin >> n >> k;

    if(n==1){
        cout << 1;
        return 0;
    }

    int n2deno = binpow((n*1LL*n)%M,M-2);
    int p = ((((n*1LL*n)%M - (2LL*n)%M + 2 + 2LL*M)%M)*1LL*n2deno)%M;
    int q = (2LL*n2deno)%M;

    int p1 = p, pelse = q;
    for(int i=2;i<=k;i++){
        int tmp1 = p1;
        p1 = ((p*1LL*p1)%M + (((q*1LL*(n-1))%M)*1LL*pelse)%M)%M;
        pelse = ((p*1LL*pelse)%M + (q*1LL*((((n-2)*1LL*pelse)%M+(tmp1))%M))%M)%M;
    }

    int deno2 = binpow(2,M-2);
    int num = ((((n*1LL*(n+1))%M)*1LL*deno2)%M - 1 + M)%M;
    cout << (p1 + (pelse*1LL*num)%M)%M;
}