#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

void solve(){
	int n,k; cin >> n >> k;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	sort(a,a+n);

	int ans = 1;
	int head=-1,tail=0;
	int curr=1;

	// for(int i=0;i<n;i++) cout << a[i] << " ";
	// cout << endl;

	while(tail<n){
		while(head+1<n && (head==tail-1 || (a[head+1]<=a[head]+1 && curr+(a[head+1]!=a[head])<=k))){
			head++;
			if(head!=tail && a[head]!=a[head-1]) curr++;
		}
		ans = max(ans,head-tail+1);
		// cout << tail << " " << head << endl;
		if(head>=tail){
			if(head!=tail && a[tail]!=a[tail+1]) curr--;
			tail++;
		}
		else{
			tail++;
			head = tail-1;
		}
	}

	cout << ans << endl;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}