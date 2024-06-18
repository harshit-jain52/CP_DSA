#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

ll dp[19][2][2][8][7][9][2];

string convert(ll num){
	string s = to_string(num);
	string ans = "";
	for(int i=0;i<19-s.size();i++) ans += '0';
	ans += s;
	return ans;
}

ll func(int id, bool lo, bool hi, int mask, int mod7, int mod9, bool lz, string &a, string &b){
	if(id==19){
		if((mask&1) && mod9%3==0) return 0;
		if((mask&2) && mod7==0) return 0;
		if((mask&4) && mod9==0) return 0;
		return 1;
	}

	if(dp[id][lo][hi][mask][mod7][mod9][lz]!=-1) return dp[id][lo][hi][mask][mod7][mod9][lz];

	int loLim = (lo?(a[id]-'0'):1);
	int hiLim = (hi?(b[id]-'0'):9);

	ll ct = 0;
	if(loLim==0 && lz) ct += func(id+1,lo,hi&&(hiLim==0),mask,mod7,mod9,lz,a,b);
	if(loLim<=3 && hiLim>=3) ct += func(id+1,lo&&(loLim==3),hi&&(hiLim==3),(mask|1),(mod7*10+3)%7,(mod9*10+3)%9,0,a,b);
	if(loLim<=7 && hiLim>=7) ct += func(id+1,lo&&(loLim==7),hi&&(hiLim==7),(mask|2),(mod7*10+7)%7,(mod9*10+7)%9,0,a,b);
	if(loLim<=9 && hiLim>=9) ct += func(id+1,lo&&(loLim==9),hi&&(hiLim==9),(mask|4),(mod7*10+9)%7,(mod9*10+9)%9,0,a,b);
	if(loLim<=5 && hiLim>=5 && id!=18) ct += func(id+1,lo&&(loLim==5),hi&&(hiLim==5),mask,(mod7*10+5)%7,(mod9*10+5)%9,0,a,b);
	
	return dp[id][lo][hi][mask][mod7][mod9][lz]=ct;
}

void solve(){
	ll a,b,k;
	cin >> a >> b >> k;

	string a_str = convert(a);
	ll lo=a,hi=b,mid;
	ll ans = -1;
	while(lo<=hi){
		mid = (lo+hi)/2;
		string m_str = convert(mid);
		memset(dp,-1,sizeof(dp));

		if(func(0,1,1,0,0,0,1,a_str,m_str)>=k){
			ans = mid;
			hi = mid-1;
		}
		else lo = mid+1;
	}
	cout << ans << endl;
}

int main()
{
	FASTIO
	int q; cin >> q;
	while(q--) solve();
}