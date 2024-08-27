#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e7+5;

int sp[N];
int gr[N];

void sieve(){
	for(int i=2;i<N;i++) sp[i]=i;

	for(int i=2;i<N;i++){
		if(sp[i]==i){
			for(ll j=i*1LL*i;j<N;j+=i) sp[j] = min(sp[j],i);
		}
	}
}

void grundy(){
	gr[1] = 1;
	gr[2] = 0;
	int num_primes=1;
	for(int i=3;i<N;i++){
		if(sp[i]==i) gr[i] = ++num_primes;
		else if(i&1) gr[i] = gr[sp[i]];
		else gr[i] = 0;
	}
}

void solve(){
	int n; cin >> n;
	int x = 0;

	for(int i=0;i<n;i++){
		int a; cin >> a;
		x^=gr[a];
	}

	cout << ((x)?"Alice\n":"Bob\n");
}

int main()
{
	FASTIO
	sieve();
	grundy();

	int t; cin >> t;
	while(t--) solve();
}