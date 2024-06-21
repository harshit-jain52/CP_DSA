#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    
    ll ans1=0;
    int last=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            ans1 += (i-last);
            last++;
        }
    }
    
    ll ans2=0;
    last=n-1;
    for(int i=n-1;i>=0;i--){
        if(arr[i]==0){
            ans2 += (last-i);
            last--;
        }
    }
    
    cout << min(ans1,ans2);
}