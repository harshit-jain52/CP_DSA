#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

bool solve(){
	int n; cin >> n;
	string s; cin >> s;

	int idx=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1') idx=i;
		else break;
	}

	if(idx==n-1){
		return (n==4 || n==1);
	}
	else{
		int c = idx;
		int r = n/c;
		return (r==c);
	}

	return 0;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		if(solve()) cout << "Yes\n";
		else cout << "No\n";
	}
}