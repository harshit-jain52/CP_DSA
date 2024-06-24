#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second

bool solve(){
    int n, m;
    cin >> n >> m;
    
    vector<pii>gifts(n),boxes(m);
    
    for(int i=0;i<n;i++) cin >> gifts[i].F >> gifts[i].S;
    for(int j=0;j<m;j++) cin >> boxes[j].F >> boxes[j].S;
    
    sort(gifts.begin(),gifts.end());
    sort(boxes.begin(),boxes.end());
    int i=n-1,j=m-1;
    
    multiset<int>ms;
    while(i>=0){
        while(j>=0 && boxes[j].F>=gifts[i].F) ms.insert(boxes[j--].S);
        
        auto it = ms.lower_bound(gifts[i].S);
        if(it==ms.end()) return false;
        ms.erase(it);
        i--;
    }
    return true;
}

int main(){
    int t; cin >> t;
    while(t--){
        if(solve()) cout << "YES\n";
        else cout << "NO\n";
    }
}