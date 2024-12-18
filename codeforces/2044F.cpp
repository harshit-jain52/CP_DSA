#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+1;
#define F first
#define S second

vector<int>divis[N];

void divisors()
{	
	for(int i=1;i<N;i++) divis[i].push_back(1);

    for (int i = 2; i < N; i++)
        for (int j = i; j < N; j += i)
            divis[j].push_back(i);
}

int main()
{
	FASTIO
	divisors();
	int n,m,q; cin >> n >> m >> q;
	vector<int>mpa(2*N,0),mpb(2*N,0);
	ll atot=0,btot=0;
	for(int i=0;i<n;i++){
		ll a; cin >> a;
		mpa[a+N]++;
		atot+=a;
	}
	for(int i=0;i<m;i++){
		ll b; cin >> b;
		mpb[b+N]++;
		btot+=b;
	}

	while(q--){
		ll x; cin >> x;
		// x = (atot - ar)*(btot - bc)
		bool neg = (x<0);
		if(neg) x = -x;

		for(auto num: divis[x]){
			ll p = num,q=x/num;
			vector<pair<ll,ll>>pp;
			if(neg){
				pp = {
					{atot+p,btot-q},
					{atot-p,btot+q}
				};
			}
			else{
				pp = {
					{atot-p,btot-q},
					{atot+p,btot+q}
				};
			}

			for(auto it: pp){
				if(it.F+N<0 || it.F+N >= 2*N || it.S+N<0 || it.S+N >= 2*N) continue;
				if(mpa[it.F+N] && mpb[it.S+N]){
					cout << "YES" << endl;
					goto endloop;
				}
			}
		}

		cout << "NO" << endl;
		endloop:
	}
}