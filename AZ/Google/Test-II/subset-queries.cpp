#include <bits/stdc++.h>
using namespace std;
const int N = 7000;
const int M = 1e9+7;

int main(){
    vector<int>ct(N+1,0);
    ct[0]=1;

    int q; cin >> q;
    while(q--){
        int tp,x; cin >> tp >> x;

        if(tp==0){
            for(int i=N;i>=x;i--) ct[i]=(ct[i]+ct[i-x])%M;
        }
        else if(tp==1){
            for(int i=x;i<=N;i++) ct[i]=(ct[i]-ct[i-x]+M)%M;
        }
        else cout << ct[x]<< " ";
    }
}