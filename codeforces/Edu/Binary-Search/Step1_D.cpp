#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int query(vector<int> &a, int l, int r){
	int n = a.size();
	int ans = n;
	
	int idx=0;
	int lo=0,hi=n-1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(a[mid]<l){
			idx = mid+1;
			lo=mid+1;
		}
		else hi=mid-1;
	}

	ans -= idx;

	idx=n+1,lo=0,hi=n-1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(a[mid]>r){
			idx = mid+1;
			hi=mid-1;
		}
		else lo=mid+1;
	}

	ans -= (n+1-idx);

	return ans;
}

int main()
{
	FASTIO
	int n,k; cin >> n;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a.begin(),a.end());
	
	cin >> k;
	while(k--){
		int l,r; cin >>l>>r;
		cout << query(a,l,r) << " ";
	}
}