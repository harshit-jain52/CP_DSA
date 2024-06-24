#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k; cin >> n >> k;
    string s; cin >> s;
    
    vector<int>ct(26,0);
    
    auto check = [&](int i)->bool{
        ct[s[i]-'a']++;
        
        int tot=0,max1=0,max2=0;
        for(int i=0;i<26;i++){
            tot += ct[i];
            if(ct[i]>max1){
                max2 = max1;
                max1 = ct[i];
            }
            else if(ct[i]>max2){
                max2 = ct[i];
            }
        }
        
        ct[s[i]-'a']--;
        
        int chng = tot-max1-max2;
        return (chng<=k);
    };
    
    int maxlen = 0;
    int tail=0,head=-1;
    
    while(tail<n){
        while(head+1<n && check(head+1)){
            head++;
            ct[s[head]-'a']++;
        }
        
        maxlen = max(maxlen,head-tail+1);
        
        if(head>=tail){
            ct[s[tail]-'a']--;
            tail++;
        }
        else{
            tail++;
            head = tail-1;
        }
    }
    
    cout << maxlen << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}