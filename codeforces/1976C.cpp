#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
    int n,m;
    cin >> n >> m;
    ll a[n+m+1],b[n+m+1];
    for(int i=0;i<n+m+1;i++) cin >> a[i];
    for(int i=0;i<n+m+1;i++) cin >> b[i];

    vector<int>nextp(n+m);
    vector<int>nextt(n+m);
    stack<int>st1,st2;
    st1.push(m+n);
    st2.push(m+n);
    for(int i=n+m-1;i>=0;i--){
        nextp[i]=st1.top();
        nextt[i]=st2.top();
        
        if(a[i]>b[i]) st1.push(i);
        else st2.push(i);
    }

    int plast=-1,tlast=-1;
    int p=0,t=0;
    ll sum =0;

    for(int i=0;i<n+m;i++){
        if(a[i]>b[i]){
            if(p<n){
                sum += a[i];
                p++;
                plast=i;
            }
            else{
                sum += b[i];
                t++;
                tlast=i;
            }
        }
        else{
            if(t<m){
                sum += b[i];
                t++;
                tlast=i;
            }
            else{
                sum += a[i];
                p++;
                plast=i;
            }
        }
    }

    for(int i=0;i<n+m;i++){
        ll tmp = sum;
        if(a[i]>b[i]){
            if(i<=plast){
                int sub = nextp[plast];
                tmp -= a[i]; tmp+=a[sub];
                tmp-=b[sub]; tmp+=b[n+m];
                
            }
            else{
                tmp -= b[i];
                tmp += b[m+n];
            }
        }
        else{
            if(i<=tlast){
                int sub = nextt[tlast];
                tmp -= b[i]; tmp+=b[sub];
                tmp-=a[sub]; tmp+=a[n+m];
            }
            else{
                tmp -= a[i];
                tmp += a[m+n];
            }
        }
        cout << tmp << " ";
    }

    cout << sum<<endl;
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