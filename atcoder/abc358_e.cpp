#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 998244353;
int fact[1005], fact_inv[1005];

int binpow(int a, int b){
	int ans = 1;
	while(b){
		if(b&1) ans = (ans*1LL*a)%M;
		a = (a*1LL*a)%M;
		b>>=1;
	}
	return ans;
}

int nCr(int n, int r){
	if(r==0 || n==r) return 1;

	int nume = fact[n];
	int deno = (fact_inv[r]*1LL*fact_inv[n-r])%M;
	return (nume*1LL*deno)%M;
}

int main()
{
	FASTIO	

	int k; cin >> k;
	fact[0]=fact_inv[0]=1;
	for(int i=1;i<=k;i++){
		fact[i] = (i*1LL*fact[i-1])%M;
		fact_inv[i] = binpow(fact[i],M-2);
	}

	int cap[27];
	for(int i=1;i<=26;i++) cin >> cap[i];

	vector<int>dp(k+1,0);
	dp[0]=1;
    
    // floyd warshall!!!!!!!
	for(int ch=1;ch<=26;ch++){
		vector<int> tmp(k+1,0);

		for(int len=1;len<=k;len++){
			for(int ct=1;ct<=min(cap[ch],len);ct++){
				tmp[len] += (nCr(len,ct)*1LL*dp[len-ct])%M;
				tmp[len]%=M;
			}
		}

		for(int len=1;len<=k;len++) dp[len] = (dp[len]+tmp[len])%M;
		// for(int len=1;len<=k;len++) cout << dp[len]<<" ";
		// cout << endl;
	}

	int sum = 0;
	for(int i=1;i<=k;i++) sum = (sum+dp[i])%M;

	cout << sum;
}