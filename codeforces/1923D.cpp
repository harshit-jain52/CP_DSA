#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 3e5+5;
const int INF = 1e7;
const int LOG = 20;

int logtwo[N];
ll a[N], mn[N][LOG], mx[N][LOG];

void solve(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		mn[i][0]=mx[i][0]=a[i];
	}

	ll pref[n+1];
	pref[0]=0;
	for(int i=1;i<=n;i++) pref[i]=pref[i-1]+a[i-1];

	for(int j=1;j<=logtwo[n];j++){
		for(int i=0;i+(1<<j)-1<n;i++){
			mn[i][j] = min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
			mx[i][j] = max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
		}
	}

	auto isValid = [&](int l, int r)->bool{
		int k = logtwo[r-l+1];

		int tmp1 = min(mn[l][k],mn[r-(1<<k)+1][k]);
		int tmp2 = max(mx[l][k],mx[r-(1<<k)+1][k]);

		return tmp1!=tmp2;
	};

	for(int i=0;i<n;i++){
		int ct = INF;

		// right
		if(i<n-1){
			if(a[i+1]>a[i]) ct=1;
			else{
				int lo=i+2,hi=n-1,mid;
				while(lo<=hi){
					mid = (lo+hi)/2;
					int l=i+1,r=mid;
					if(pref[r+1]-pref[l]>a[i] && isValid(l,r)){
						ct = min(ct,mid-i);
						hi=mid-1;
					}
					else lo=mid+1;
				}
			}
		}

		// left
		if(i>0){
			if(a[i-1]>a[i]) ct=1;
			else{
				int lo=0,hi=i-1,mid;
				while(lo<=hi){
					mid = (lo+hi)/2;
					int l=mid,r=i-1;
					if(pref[r+1]-pref[l]>a[i] && isValid(l,r)){
						ct = min(ct,i-mid);
						lo=mid+1;
					}
					else hi=mid-1;
				}	
			}
		}

		cout<<((ct==INF)?-1:ct)<<" ";
	}
}

int main()
{
	FASTIO

	logtwo[1]=0;
	for(int i=2;i<N;i++) logtwo[i]=1+logtwo[i/2];

	int t;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
}