#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

vector<int> manacher(string s){
	string t = "#";
	for(char c: s){
		t += c;
		t += '#';
	}

	int n = t.length();
	vector<int>p(n,1);
	int l=1,r=1;

	for(int i=1;i<n;i++){
		p[i] = max(1,min(r-i,p[l+r-i]));

		while(i+p[i]<n && i-p[i]>=0 && t[i+p[i]]==t[i-p[i]]) p[i]++;

		if(i+p[i]>r){
			r = i+p[i];
			l = i-p[i];
		}
	}

	return p;
}

void solve(){
	string s; cin >> s;
	int n = s.size();

	vector<int>pal = manacher(s+s);
	int sz = pal.size();

	int ct =0;
	// for(int i=0;i<sz;i++) cout << pal[i]<<" ";
	for(int i=n, k=0;k<n;i+=2, k++){
		int len = pal[i]-1;
		if(len>=n) ct++;
	}

	cout << ct<<endl;
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