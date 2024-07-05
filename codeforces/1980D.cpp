#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

bool check(int skip, vector<int>&a){
	vector<int>vec;
	int n = a.size();
	for(int i=0;i<n;i++) if(i!=skip) vec.push_back(a[i]);

	for(int i=1;i<n-2;i++){
		if(__gcd(vec[i],vec[i-1])>__gcd(vec[i],vec[i+1])) return false;
	}
	return true;
}

void solve(){
	int n; cin >> n;
	vector<int>a(n);
	for(int i=0;i<n;i++) cin >> a[i];

	int idx = -1;
	for(int i=1;i<n-1;i++){
		if(__gcd(a[i],a[i-1]) > __gcd(a[i],a[i+1])){
			idx = i;
			break;
		}
	}

	if(idx==-1 || n==3){
		cout << "YES\n";
		return;
	}

	if(check(idx,a) || check(idx-1,a) || check(idx+1,a)) cout << "YES\n";
	else cout << "NO\n";
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