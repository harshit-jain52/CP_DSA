#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int k;
string s;
int sz;
const int LCM = 504; // lcm of 1,2...9 (except 5) = 504
ll dp[19][LCM][512][2][2];
int prec[LCM][10];
bool divis[LCM][10];

void precomp(){
	for(int i=0;i<LCM;i++){
		for(int j=0;j<10;j++){
			prec[i][j] = (i*10+j)%LCM;
			if(j>0) divis[i][j] = (i%j==0);
		}
	}
}

ll func(int id, bool hi, int mod, int mask, bool last5){
	if(id==sz){
		int sp=0;
		for(int d=1;d<=9;d++){
			if(d!=5 && (mask>>(d-1))&1 && divis[mod][d]) sp++;
		}
		if(last5 && (mask>>4)&1) sp++;
		return (sp>=k);
	}

	if(dp[id][mod][mask][hi][last5]!=-1) return dp[id][mod][mask][hi][last5];

	int hiLim = (hi?s[id]-'0':9);
	ll ct = 0;
	for(int d=0;d<=hiLim;d++){
		ct += func(id+1,hi&&(hiLim==d),prec[mod][d],(mask|(d>0?(1<<(d-1)):0)),(d==5||d==0));
	}

	return dp[id][mod][mask][hi][last5] = ct;
}

void solve(){
	ll l,r;
	cin >> l >> r >> k;

	memset(dp,-1,sizeof(dp));
	s = to_string(r); sz = s.size();
	ll ctr = func(0,1,0,0,0);

	memset(dp,-1,sizeof(dp));
	s = to_string(l-1); sz=s.size();
	ll ctl = (l>1)?func(0,1,0,0,0):0;

	cout << ctr-ctl<<endl;
}

int main()
{
	FASTIO
	precomp();
	int q; cin >> q;
	while(q--) solve();
}