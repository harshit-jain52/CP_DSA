#include <bits/stdc++.h>
using namespace std;

string getMaximum(string& S, string& T)
{
    if (S.find("0") != string::npos) return T;
    if (T.find("0") != string::npos) return S;
    return (S.length() > T.length() ? S : T);
}
 
string recursion(int arr[], int idx, int N, int K, vector<vector<string> >& dp)
{
    if (K == 0) return "";
    if (K < 0 or idx == N) return "0";
 
    if (dp[idx][K] != "-1") return dp[idx][K];
 
    string include = to_string(idx + 1) + recursion(arr,0,N,K-arr[idx],dp);
    string exclude = recursion(arr,idx+1,N,K,dp);
 
    return dp[idx][K] = getMaximum(include, exclude);
}
 
string largestNumber(int arr[], int N, int K)
{
    vector<vector<string> > dp(N + 1, vector<string>(K + 1,"-1"));
    string ans = recursion(arr, 0, N, K, dp);
    return (ans == "0" ? "IMPOSSIBLE" : ans);
}

void solve(){
    int k; cin >> k;
    int a[9];
    for(int i=0;i<9;i++) cin >> a[i];

    cout << largestNumber(a, 9, k) << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}