#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int INV2 = 500000004;

ll n,z;
int dp[61][2][2][2];

inline ll xorN(ll N){
	if(N%4==0) return N;
	else if(N%4==1) return 1;
	else if(N%4==2) return N+1;
	return 0;
}


int func(int bit, bool hix, bool hiy, bool carryReq){
	if(bit==-1) return !carryReq;
	if(dp[bit][hix][hiy][carryReq]!=-1) return dp[bit][hix][hiy][carryReq];

	int xLim = hix?((n>>bit)&1):1;
	int yLim = hiy?((n>>bit)&1):1;

	int zbit = (z>>bit)&1;
	int ct = 0;
	for(int x=0;x<=xLim;x++) for(int y=0;y<=yLim;y++){
		if(x==y){
			if(x==0 && !carryReq) ct = (ct+func(bit-1,hix&&(xLim==x),hiy&&(yLim==y),zbit))%M;
			else if(x==1 && carryReq) ct = (ct+func(bit-1,hix&&(xLim==x),hiy&&(yLim==y),zbit))%M;
		}
		else{
			if(!zbit && !carryReq) ct = (ct+func(bit-1,hix&&(xLim==x),hiy&&(yLim==y),0))%M;
			else if(zbit && carryReq) ct = (ct+func(bit-1,hix&&(xLim==x),hiy&&(yLim==y),1))%M;
		}
	}

	return dp[bit][hix][hiy][carryReq] = ct;	
}

void solve(){
	cin >> n;
	z = xorN(n);

	// find x,y for x^y^(x+y) == z
	
	memset(dp,-1,sizeof(dp));
	int ct = func(60,1,1,0);

	if(z==0) ct = (ct-2*n+M)%M;
	if(z%2==0 && z/2<=n) ct = (ct-1+M)%M;

	cout << (ct*1LL*INV2)%M << endl;

}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}

// https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/unfair-nim-afea7c42/