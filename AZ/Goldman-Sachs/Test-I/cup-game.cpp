#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;

    vector<bool>b{1,0,0};
    for(char c: s){
        if(c=='A') swap(b[0],b[1]);
        else if(c=='B') swap(b[1],b[2]);
        else swap(b[0],b[2]);
    }

    for(int i=0;i<3;i++) if(b[i]) cout << (i+1) << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}