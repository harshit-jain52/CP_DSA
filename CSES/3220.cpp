#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e7;

ll arr[N];

void gen(int x, int a, int b, int c, int n){
	arr[0]=x;
	for(int i=1;i<n;i++) arr[i]=(a*arr[i-1]+b)%c;
}

int main()
{
	FASTIO
	int n,k; cin >> n >> k;
	int x,a,b,c; cin >> x >> a >> b >> c;

	gen(x,a,b,c,n);

	ll ans=0;
	ll curr=0;
	int i=0;
	while(i<k){
		curr+=arr[i];
		i++;
	}
	ans = curr;

	while(i<n){
		curr -= arr[i-k];
		curr += arr[i];
		ans ^= curr;
		i++;
	}

	cout << ans << endl;
}