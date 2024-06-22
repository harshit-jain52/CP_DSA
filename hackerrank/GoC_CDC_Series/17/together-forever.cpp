#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,m; cin >> n >> m;
    string s; cin >> s;
    int first=-1, last=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='X'){
            first = i;
            break;
        }
    }
    
    for(int i=first;i<n;i++){
        if(s[i]=='X') last = i;
    }
    
    int numD=0, numX=0;
    vector<int>vec;
    for(int i=first; i<=last; i++) {
        numD += (s[i]=='D');
        if(s[i]=='X'){
            vec.push_back(i-numX);
            numX++;
        }
    }
    
    ll moves;
    if(numX==1) moves=0;
    else{
        sort(vec.begin(),vec.end());
        int med1 = vec[numX/2], med2 = vec[numX/2 - 1];

        ll tmp1=0, tmp2=0;
        for(int i=0;i<numX;i++) {
            tmp1 += abs(vec[i]-med1);
            tmp2 += abs(vec[i]-med2);
        }

        moves = min(tmp1,tmp2);
    }
    

    while(m--){
        ll p,q; cin >> p >> q;
        cout << p*moves + q*numD << " ";
    }
    cout << endl;
}
int main(){
    int t; cin >> t;
    while(t--) solve();
}