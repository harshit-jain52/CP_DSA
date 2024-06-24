#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    int i,k;
    int tot=0, reqPal=0, pairs=0;
    for(i=0;i<n;i++) tot+=(s[i]=='0');
    
    i=0,k=n-1;
    while(i<k){
        reqPal += (s[i]!=s[k]);
        pairs += (s[i]==s[k] && s[i]=='0');
        i++; k--;
    }
    
    int o=0,j=0;
    int mid = tot-reqPal-2*pairs;
    // cout << reqPal<<" "<<pairs<<" "<<mid<<endl;
    
    if(reqPal>0){
        if(mid){
            j+=reqPal;
            o++;

            if(pairs){
                j+=pairs+1;
                o+=pairs-1;    
            }
        }
        else{
            if(pairs){
                j+=reqPal-1;
                o++;
                j+=pairs+1;
                o+=pairs-1;
            }
            else{
                j+=reqPal;
            } 
        }
    }
    else{
        if(mid){
            o++;
            if(pairs){
                j+=pairs+1;
                o+=pairs-1;    
            }
        }
        else{
            if(pairs){
                o+=pairs+1;
                j+=pairs-1;
            }
            
        }
    }
    
    cout << o << " "<< j << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}