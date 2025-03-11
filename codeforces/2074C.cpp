#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

bool degenerate(int a, int b, int c){
	if(a+b<=c) return false;
	if(a+c<=b) return false;
	if(c+b<=a) return false;
	return true;
}

ll solve(){
	ll x; cin >> x;
	int l0=-1,l1=-1;
	for(ll bit=0; bit<=30; bit++){
		ll num = (1LL<<bit);
		if(l0==-1){
			if(((x>>bit)&1)==0) l0=bit;
		}
		else if(l1==-1){
			if(((x>>bit)&1)==1) l1=bit;
		}
	}

	if(l0!=-1 && l1!=-1){
		ll y = x^(1LL<<l0)^(1LL<<l1);
		if(degenerate(x,y,x^y)) return y;
	}
	return -1;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		cout << solve() << endl;
	}
}