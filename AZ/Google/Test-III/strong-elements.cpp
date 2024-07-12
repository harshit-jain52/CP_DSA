#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int>fin;
    for(int i=0;i<n;i++){
        if(a[i]>0) fin.push_back(a[i]);
        else{
            while(fin.size() && fin.back()>0 && fin.back()<abs(a[i])) fin.pop_back();
            if(fin.size() && fin.back()>=abs(a[i])){
                if(fin.back()==abs(a[i])) fin.pop_back();
            }
            else fin.push_back(a[i]);
        }
    }
    
    cout << fin.size()<<endl;
    for(int it: fin) cout << it << " ";
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}