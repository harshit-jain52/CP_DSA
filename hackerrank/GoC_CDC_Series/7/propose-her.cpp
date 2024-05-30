#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

vector<string>vec;

void func(int l,int r,string &s){
    if(r<l) return;
    if(l==0 && r==0) {
        vec.push_back(s);
        return;
    }
    
    if(l>0){
        s.push_back('(');
        func(l-1,r,s);
        s.pop_back();
    }
    
    if(r>0){
        s.push_back(')');
        func(l,r-1,s);
        s.pop_back();
    }
}

int main(){
    FASTIO
    int n;
    cin >> n;
    string tmp = "";
    func(n,n,tmp);
    cout << vec.size()<<endl;
    for(auto s : vec) cout << s << endl;
}