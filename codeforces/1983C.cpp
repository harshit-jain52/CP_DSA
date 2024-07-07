#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

vector<int> abc(ll a[], ll b[], ll c[], ll x, int n){
	ll apref[n+1], bpref[n+1], cpref[n+1];

	apref[0]=bpref[0]=cpref[0]=0;
	for(int i=1;i<=n;i++){
		apref[i] = apref[i-1]+a[i-1];
		bpref[i] = bpref[i-1]+b[i-1];
		cpref[i] = cpref[i-1]+c[i-1];
	}

	int tail=0,head=-1;
	ll curr = 0;

	while(tail<n){
		while(head+1<n && curr<x){
			head++;
			curr += a[head];
		}

		if(curr>=x){
			// cout << "here"<<tail<<" "<<head<<endl;
			if(bpref[tail]>=x && n>=head+2 && cpref[n]-cpref[head+1]>=x){
				return vector<int>{tail+1,head+1,1,tail,head+2,n};
			}
		}

		if(head>=tail){
			curr -= a[tail];
			tail++;
		}
		else{
			tail++;
			head = tail-1;
		}
	}

	return vector<int>{-1};
}

void solve(){
	int n; cin >> n;
	ll a[n],b[n],c[n],tot;

	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	for(int i=0;i<n;i++) cin >> c[i];

	tot = accumulate(a,a+n,0LL);

	vector<int>ans;
	ll x = (tot+3-1)/3;
	// cout << x << endl;

	ans = abc(a,b,c,x,n);
	if(ans.size()!=1){
		cout << ans[0] << " " <<ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4]<< " " << ans[5];
		return;
	}

	ans = abc(a,c,b,x,n);
	if(ans.size()!=1){
		cout << ans[0] << " " <<ans[1] << " " << ans[4] << " " << ans[5] << " " << ans[2]<< " " << ans[3];
		return;
	}

	ans = abc(b,a,c,x,n);
	if(ans.size()!=1){
		cout << ans[2] << " " <<ans[3] << " " << ans[0] << " " << ans[1] << " " << ans[4]<< " " << ans[5];
		return;
	}

	ans = abc(b,c,a,x,n);
	if(ans.size()!=1){
		cout << ans[4] << " " <<ans[5] << " " << ans[0] << " " << ans[1] << " " << ans[2]<< " " << ans[3];
		return;
	}

	ans = abc(c,a,b,x,n);
	if(ans.size()!=1){
		cout << ans[2] << " " <<ans[3] << " " << ans[4] << " " << ans[5] << " " << ans[0]<< " " << ans[1];
		return;
	}

	ans = abc(c,b,a,x,n);
	if(ans.size()!=1){
		cout << ans[4] << " " <<ans[5] << " " << ans[2] << " " << ans[3] << " " << ans[0]<< " " << ans[1];
		return;
	}
	cout << -1;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
}