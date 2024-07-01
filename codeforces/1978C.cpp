#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
    int n; ll k;
    cin >> n >> k;

    ll maxk;
    if(n&1){
        int num = n/2;
        maxk = 2LL*num*(num+1);
    }
    else{
        int num = n/2;
        maxk = 2LL*num*num;
    }


    if((k&1) || k>maxk){
        cout << "No\n";
        return;
    }
    
    int p[n+1];
    for(int i=1;i<=n;i++) p[i]=i;

    int i=1,j=n;
    while(i<j){
        if(k>=(j-i)*2){
            swap(p[i],p[j]);
            k -= 2*(j-i);
            i++;
            j--;
        }
        else j--;
    }

    cout << "Yes\n";
    for(int i=1;i<=n;i++) cout << p[i] << " ";
    cout << endl;
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