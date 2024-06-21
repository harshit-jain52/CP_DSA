#include <bits/stdc++.h>
using namespace std;

int main(){
    int q; cin >> q;
    vector<int>XOR(2,0);
    vector<int>arr{0};
    int sz = 1;
    while(q--){
        int tp,x; cin >> tp >> x;
        if(tp==1){
            arr.push_back(x);
            XOR.push_back(0);
            sz++;
        }
        else{
            XOR[0]^=x;
            XOR[sz]^=x;
        }
    }
    
    for(int i=1;i<sz;i++) XOR[i]^=XOR[i-1];
    for(int i=0;i<sz;i++) arr[i]^=XOR[i];
    
    sort(arr.begin(),arr.end());
    for(int i=0;i<sz;i++) cout << arr[i] << " ";
}