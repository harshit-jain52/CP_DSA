#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n; ll s;
	cin >> n >> s;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	ll pref=0;
	int head=-1,tail=0;
	ll sum = 0;

	while(tail<n){
		while(head+1<n && pref+a[head+1]<=s){
			head++;
			pref += a[head];
		}
		ll ct = (head-tail+1);
		sum += ct*(ct+1)/2;

		if(head>=tail){
			pref -= a[tail];
			tail++;
		}
		else{
			tail++;
			head = tail-1;
		}
	}

	cout << sum;
}