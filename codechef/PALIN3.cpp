#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
ll ans = 0;

vector<int> manacher(string s){
	string t = "#";
	for(char c: s){
		t += c;
		t += '#';
	}

	int n = t.length();
	int pref[n], ct[n][3];
	pref[0]=0;
	for(int j=0;j<3;j++) ct[0][j]=0;

	for(int i=1;i<n;i++){
		pref[i]=pref[i-1];
		for(int j=0;j<3;j++) ct[i][j] = ct[i-1][j];

		if(t[i]!='#'){
			pref[i]+= (t[i]-'0');
			pref[i]%=3;
			if(t[i]!='0') ct[i][pref[i]]++;

			// cout << pref[i]<<" "<<ct[i][0]<<" "<<ct[i][1]<<" "<<ct[i][2]<<endl;
		}

	}

	vector<int>p(n,1);
	int l=1,r=1;

	for(int i=1;i<n;i++){
		p[i] = max(1,min(r-i,p[l+r-i]));

		while(i+p[i]<n && i-p[i]>=0 && t[i+p[i]]==t[i-p[i]]) p[i]++;

		if(i+p[i]>r){
			r = i+p[i];
			l = i-p[i];
		}

		int hi=i+p[i]-1;
		int x=0;
		if(t[i]!='#') x = ((t[i]-'0')%3);
		if(t[i]!='#' && (t[i]-'0')%3==0) ans++;
		
		x = (pref[i]+x)%3;
		ans += (ct[hi][x] - ct[i][x]);
		
		// cout << p[i]<<" "<<ans << endl;
	}

	return p;
}

int main()
{
	FASTIO
	string s; cin >> s;
	manacher(s);
	cout << ans;
}