#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
    int n,k;
    cin >> n >> k;

    vector<int>vec;
    if(k+1<n) vec.push_back(k+1);

    int curr = 0;
    int num = 1;
    while(1){
        if(curr+num >=k) break;
        curr+=num;
        vec.push_back(num);
        num=curr+1;
    }

    if(k-curr>1){
        vec.push_back(k-curr-1);
        curr = k-1;
    }

    num=k+1;
    while(num<=n){
        curr+=num;
        vec.push_back(num);        
        num=curr+1;
    }
    
    cout << vec.size()<<endl;
    for(auto i: vec) cout << i << " ";
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