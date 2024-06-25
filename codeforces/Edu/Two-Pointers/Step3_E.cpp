#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n, s;
	cin >> n >> s;
	int w[n],c[n];
	for(int i=0;i<n;i++) cin >> w[i];
	for(int i=0;i<n;i++) cin >> c[i];

	ll cost=0, wt=0;
	int head=-1,tail=0;
	ll ans = 0;

	while(tail<n){
		while(head+1<n && wt+w[head+1]<=s){
			head++;
			wt += w[head];
			cost += c[head];
			ans = max(ans,cost);
		}

		if(head>=tail){
			wt -= w[tail];
			cost -= c[tail];
			tail++;
		}
		else{
			tail++;
			head = tail-1;
		}
	}

	cout << ans;
}