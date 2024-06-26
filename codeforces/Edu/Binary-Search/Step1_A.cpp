#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

bool check(vector<int> &a, int num){
	int n = a.size();
	int lo=0,hi=n-1;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(a[mid]==num) return true;
		if(a[mid]>num) hi=mid-1;
		else lo=mid+1;
	}
	return false;
}

int main()
{
	FASTIO
	int n,k; cin >> n >> k;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin >> a[i];

	while(k--){
		int num; cin >> num;
		if(check(a,num)) cout << "YES\n";
		else cout << "NO\n";
	}
}