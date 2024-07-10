#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

struct People{
	ll nume,deno;
	int assgn;

	People(){}
	bool operator<(People other){
		if(nume*other.deno!=other.nume*deno) return nume*other.deno>other.nume*deno;
		return assgn < other.assgn;
	}
};

int main()
{
	FASTIO
	int n; cin >> n;
	vector<People>vec(n);

	for(int i=0;i<n;i++){
		ll a,b; cin >> a >> b;
		vec[i].nume = a;
		vec[i].deno = a+b;
		vec[i].assgn=i+1;
	}

	sort(vec.begin(),vec.end());

	for(int i=0;i<n;i++) cout << vec[i].assgn << " ";
}