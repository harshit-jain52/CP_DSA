#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

vector<int> manacher(string &s){
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

int main()
{
	FASTIO
	string s; cin >> s;
	vector<int>pal = manacher(s);

	ll num = 0;
	int sz = pal.size();
	for(int i=0;i<sz;i++){
		num += (pal[i]-(i%2==0))/2;
	}
	cout << num;
}