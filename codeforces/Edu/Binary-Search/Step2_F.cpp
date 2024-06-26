#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	string t,p;
	cin >> t >> p;

	int n = t.size(), m = p.size();
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	int lo=0,hi=n,mid;
	int ans = lo;

	while(lo<=hi){
		int mid = (lo+hi)/2;

		string tmp=t;
		for(int i=0;i<mid;i++) tmp[a[i]-1]='#';
		string s="";
		for(int i=0;i<n;i++) if(tmp[i]!='#') s.push_back(tmp[i]);

		int sz=s.size(),i=0,j=0;
		while(i<sz && j<m){
			if(s[i]==p[j]) j++;
			i++;		
		}
		
		if(j==m){
			ans = mid;
			lo = mid+1;
		}
		else hi=mid-1;
	}

	cout << ans;
}