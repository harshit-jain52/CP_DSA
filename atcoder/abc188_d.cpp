#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n; ll cy;
	cin >> n >> cy;
	vector<pair<pair<ll,ll>,ll>>serv;

	map<ll,int>comp;

	for(int i=0;i<n;i++){
		ll a,b,c;
		cin >> a >> b >> c;
		comp[a]; comp[b+1];
		serv.push_back({{a,b},c});
	}

	int ct=0;
	vector<int>revComp;
	for(auto &it:comp){
		it.second = ct++;
		revComp.push_back(it.first);
	}

	vector<ll>pay(ct+1,0);
	for(auto sv:serv){
		ll a=sv.F.F,b=sv.F.S,c=sv.S;
		pay[comp[a]]+=c;
		pay[comp[b+1]]-=c;
	}

	for(int i=1;i<=ct;i++) pay[i]+=pay[i-1];

	ll cost=0;
	for(int i=1;i<=ct;i++){
		ll tmp = min(pay[i-1],cy);
		ll rng = revComp[i]-revComp[i-1];
		cost += rng*tmp;
	}

	cout << cost;
}