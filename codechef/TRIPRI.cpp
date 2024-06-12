#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;
vector<bool>isPrime(N,true);
vector<int>primes;
void sieve(){
	isPrime[1]=false;
	for(int i=2;i<N;i++){
		if(isPrime[i]){
			primes.push_back(i);
			for(int j=2*i;j<N;j+=i){
				isPrime[j]=false;
			}
		}
	}
}

bool solve(){
	ll n; cin >> n;

	if(n<=4) return false;

	// n is even, one must be 2
	n-=4;

	for(int num: primes){
		if(num==2) continue;
		ll sq = num*1LL*num;
		if(n<=sq) break;

		ll rem = n-sq;
		ll num2 = sqrt(rem);
		if(num2*num2 != rem) continue;
		if(isPrime[num2] && num2!=num) return true;
	}

	return false;
}

int main()
{
	FASTIO
	sieve();
	int t;
	cin >> t;
	while(t--){
		if(solve()) cout << "Yes\n";
		else cout << "No\n";
	}
}