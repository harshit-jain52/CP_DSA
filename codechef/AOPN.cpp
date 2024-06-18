#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

ll dp[19][2][2][2][11][11][2][2];

string convert(ll num){
	string s = to_string(num);
	string ans = "";
	for(int i=0;i<19-s.size();i++) ans += '0';
	ans += s;
	return ans;
}

ll func(int id, bool lo, bool hi, bool lz, int last, int last2, bool o, bool e, string &a, string &b){
	if(id==19) return (o&&e);
	if(dp[id][lo][hi][lz][last][last2][o][e]!=-1) return dp[id][lo][hi][lz][last][last2][o][e];

	int loLim = (lo?a[id]-'0':0);
	int hiLim = (hi?b[id]-'0':9);

	ll ct = 0;
	for(int d=loLim;d<=hiLim;d++){
		if(d==0 && lz) ct += func(id+1,1,hi&&(hiLim==0),lz,10,10,0,0,a,b);
		else ct += func(id+1,lo&&(loLim==d),hi&&(hiLim==d),0,d,last,(o||(d==last2)),(e||(d==last)),a,b);
	}

	return dp[id][lo][hi][lz][last][last2][o][e]=ct;
}

bool isAllPal(ll num){
	string s = to_string(num);
	bool o=false,e=false;

	int sz = s.size();
	for(int i=1;i<sz;i++){
		if(s[i]==s[i-1]) e = true;
		if(i>=2 && s[i]==s[i-2]) o = true;
	}

	return (o&&e);
}

void solve(){
	memset(dp,-1,sizeof(dp));
	ll a,b;
	cin >> a >> b;
	string a_str = convert(a), b_str = convert(b);
	ll ct = func(0,1,1,1,10,10,0,0,a_str,b_str);
	cout << ct - isAllPal(a) << endl;
}

int main()
{
	FASTIO
	int t; cin >> t;
	while(t--) solve();
}