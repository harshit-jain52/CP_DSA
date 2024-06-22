#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    vector<ll>ct1(7,0), ct2(7,0), ct3(7,0);
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        ct1[num%7]++;
    }
    cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        ct2[num%7]++;
    }
    cin >> n;
    for(int i=0;i<n;i++){
        int num; cin >> num;
        ct3[num%7]++;
    }
    
    ll ans = 0;
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            for(int k=0;k<7;k++){
                if((i+j+k)%7==0) ans += ct1[i]*ct2[j]*ct3[k];
            }
        }
    }
    
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}