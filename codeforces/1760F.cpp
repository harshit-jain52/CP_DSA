#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9+7;

bool func(ll k, ll n, ll c, ll d, ll a[]){
	ll sum = 0;
	ll seg = d/k, rem = d%k;
	ll tmpsum=0;

	for(int i=0;i<min(k,n);i++){
		tmpsum+=a[i];
	}
	sum += seg*tmpsum;

	for(int i=0;i<min(rem,n);i++){
		sum+=a[i];
	}

	return sum>=c;
}
void solve(){
	ll n,c,d;
	cin >> n >> c >> d;
	ll a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	reverse(a,a+n);

	if(a[0]*d < c){
		cout << "Impossible"<< endl;
		return;
	}
	ll sumd = 0;
	for(int i=0;i<min(d,n);i++){
		sumd+=a[i];
	}
	if(sumd>=c){
		cout << "Infinity"<<endl;
		return;
	}

	ll lo = 1,hi=d,mid;
	while(hi-lo>1){
		mid = (lo+hi)/2;
		if(func(mid,n,c,d,a))
			lo = mid;
		else
			hi = mid-1;
	}

	if(func(hi,n,c,d,a)) cout << hi-1;
	else cout << lo-1;
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}