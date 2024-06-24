#include <bits/stdc++.h>
using namespace std;

string str3(char a, char b, char c){
    string str="";
    str+=a;
    str+=b;
    str+=c;
    return str;
}

void solve(){
    int n,m,q; cin >> n >> m >> q;
    
    vector<string>grid(n);
    for(int i=0;i<n;i++) cin >> grid[i];
    
    vector<vector<bool>>yes(26,vector<bool>(26,false));
    
    set<string>st;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        if(i<n-1) yes[grid[i][j]-'a'][grid[i+1][j]-'a']=true;
        if(j<m-1) yes[grid[i][j]-'a'][grid[i][j+1]-'a']=true;
        
        if(i<n-2) st.insert(str3(grid[i][j],grid[i+1][j],grid[i+2][j]));
        if(j<m-2) st.insert(str3(grid[i][j],grid[i][j+1],grid[i][j+2]));
    }
    
    while(q--){
        string s; cin >> s;
        int sz = s.size();
        vector<string>vec;
        
        string t="";
        t+=s[0];
        for(int i=1;i<sz;i++){
            if(yes[s[i-1]-'a'][s[i]-'a']) t+=s[i];
            else{
                vec.push_back(t);
                t="";
                t+=s[i];
            }            
        }
        vec.push_back(t);
        
        bool flag = true;
        for(string &it: vec){
            int x = it.size();
            if(x%2==0) continue;
            if(x==1){
                flag = false;
                break;
            }
            bool found = false;
            for(int i=0;i<=x-3;i+=2){
                string tmp = str3(it[i],it[i+1],it[i+2]);
                if(st.find(tmp)!=st.end()){
                    found = true;
                    break;
                }
            }
            if(!found){
                flag = false;
                break;
            }
        }
        
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}