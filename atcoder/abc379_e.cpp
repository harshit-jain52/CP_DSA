#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n; cin >> n;
	string s; cin >> s;
	// cout << n << " " << s << endl;
	vector<ll>digval(n,0);
	for(int i=0;i<n;i++){
		digval[i]=(s[i]-'0')*1LL*(i+1);
		if(i) digval[i]+=digval[i-1];
	}

	string t="";
	ll carry=0;
	for(int i=n-1;i>=0;i--){
		ll sum = digval[i]+carry;
		t+=('0'+sum%10);
		carry = sum/10;
	}

	if(carry){
		string c = to_string(carry);
		reverse(c.begin(),c.end());
		t = t+c;
	}
	reverse(t.begin(),t.end());
	cout << t;
}