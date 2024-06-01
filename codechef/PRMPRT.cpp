#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e6+1;
int sp[N];

void sieve(){
    for(int i=2;i<N;i++) sp[i]=i;

    for(int i=2;i<N;i++){
        if(sp[i]==i){
            for(int j=2*i;j<N;j+=i) sp[j]=min(sp[j],i);
        }
    }
}

int main()
{
    FASTIO
    sieve();
    int n,q;
    cin >> n>>q;

    while(q--){
        int a,b;
        cin >> a >> b;

        if(a==b){
            cout << 0 << endl;
            continue;
        }

        if(a>b) swap(a,b);

        bool apr = (sp[a]==a);
        bool bpr = (sp[b]==b);
        
        if(apr && b%a==0) cout << 1;
        else if(__gcd(a,b)!=1) cout << 2;
        else if(sp[a]*1LL*sp[b]<=n) cout << !apr + !bpr + 2;
        else if(sp[a]*2<=n && sp[b]*2<=n) cout << !apr + !bpr + 4;
        else cout << -1;

        cout << endl;
    }

}