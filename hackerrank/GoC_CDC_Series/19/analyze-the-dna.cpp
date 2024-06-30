#include <bits/stdc++.h>
using namespace std;

int lps(string &s){
    string t = s;
    reverse(t.begin(),t.end());
    int n = s.size();
    
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++) dp[i][0]=dp[0][i]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(s[i-1]==t[j-1]) dp[i][j] = max(dp[i][j],1+dp[i-1][j-1]);
        }
    }
    
    return dp[n][n];
}

void solve(){
    string dna; cin >> dna;
    int n = dna.size();
    int fA=-1,fG=-1,lA=-1,lG=-1;
    
    for(int i=0;i<n;i++){
        if(dna[i]=='A'){
            if(fA==-1) fA=i;
            lA = i;
        }
        else if(dna[i]=='G'){
            if(fG==-1) fG=i;
            lG=i;
        }
    }
    
    int lenA,lenG;
    if(fA==-1) lenA=0;
    else if(fA==lA) lenA=1;
    else if(fA+1==lA) lenA=2;
    else{
        string s = dna.substr(fA+1,lA-fA-1);
        lenA = 2+lps(s);
    }
    
    if(fG==-1) lenG=0;
    else if(fG==lG) lenG=1;
    else if(fG+1==lG) lenG=2;
    else{
        string s = dna.substr(fG+1,lG-fG-1);
        lenG = 2+lps(s);
    }
    
    cout << lenA << " "<<lenG << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}