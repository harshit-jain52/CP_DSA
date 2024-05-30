#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>far(n,0);
    for(int i=0;i<n;i++){
        int a; cin >> a;
        int l = max(0,i-a), r = min(n-1,i+a);
        far[l]=max(far[l],r);
    }
    
    int ct=1,cur=far[0],next=far[0];
    for(int i=1;i<n;i++){
        next=max(next,far[i]);
        if(i==cur+1){
            ct++;
            cur=next;
        }
    }
    cout << ct;
}