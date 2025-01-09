#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
const int M = 1e9+7;
#define F first
#define S second

ostream& operator<<(ostream& os, const pii& p) {
    os << "(" << p.F << ", " << p.S << ")";
    return os;
}

void solve(){
	int n; cin >> n;
	vector<pii>a(n);
	for(int i=0;i<n;i++){
		cin >> a[i].F;
		a[i].S=i;
	}

	sort(a.begin(),a.end());

	// for(int i=0;i<n;i++) cout << a[i];
	// cout << endl;

	int flag=-1, lastidx=-1;
	for(int i=0;i<n;i++){
		if(flag!=-1 && a[i].F>flag) a[i].F++;
		else if(a[i].S<lastidx){
			a[i].F++;
			if(flag==-1) flag=a[i].F;
		}
		else lastidx=a[i].S;
	}

	sort(a.begin(),a.end());
	for(int i=0;i<n;i++) cout << a[i].F<<" ";
	cout << endl;
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