#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int dp[10005][10][105];

vector<int> prefix_function(string &s){
    int n = s.length();
    vector<int> lps(n+1);

    int i=0, j=-1;
    lps[0] = -1;

    while (i<n){
        while (j!=-1 && s[j]!=s[i]) j=lps[j];
        
        i++; j++;
        lps[i] = j;
    }

    return lps;
}

int main()
{
	FASTIO

	vector<string>key={"46","68","79","48","039","","017","26","13","24"};
	int n,m,k; cin >> n >> m >> k;

	if(m==0){
		vector<vector<int>>dp0(n+1,vector<int>(10,0));
		dp0[0][k]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=9;j++){
				for(char c: key[j]) dp0[i][j] = (dp0[i][j]+dp0[i-1][c-'0'])%M;
			}
		}

		int ans = 0;
		for(int j=0;j<=9;j++) ans = (ans+dp0[n][j])%M;
		cout << ans << endl;
	}
	else{
		string t; cin >> t;
		memset(dp,0,sizeof(dp));

		vector<int>pref = prefix_function(t);
		int kmp[m+1][10];
		for(int j=0;j<=9;j++){
			int i=0,p=-1;
			kmp[0][j]=pref[0];
			while(i<m){
				while(p!=-1 && t[p]!=('0'+j)) p = pref[p];

				i++; p++;
				kmp[i][j]=p;
			}
		}

		dp[0][k][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=9;j++){
				for(int x=1;x<=m;x++){
					for(char c: key[j]){
						if(j==t[x-1]-'0'){
							dp[i][j][x] += dp[i-1][c-'0'][x-1];
							dp[i][j][x]%=M;
						}
						else{
							dp[i][j][kmp[x][j]] += dp[i-1][c-'0'][x-1];
							dp[i][j][kmp[x][j]]%=M;
						}
					}
				}
			}
		}

		int ans = 0;
		for(int i=0;i<m;i++){
			for(int j=0;j<=9;j++){
				ans += dp[n][j][i];
				ans %= M;
			}
		}
		cout << ans << endl;
	}
}