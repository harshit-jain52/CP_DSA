#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,k; cin >> n >> k;

	int x[n];
	for(int i=0;i<n;i++) cin >> x[i];

	map<int,int> mp;
	for(int i=0;i<k;i++) mp[x[i]]++;
	cout << mp.size() << " ";

	for(int i=k;i<n;i++){
		mp[x[i]]++;
		if((--mp[x[i-k]])==0) mp.erase(x[i-k]);
		cout << mp.size() << " ";
	}	
}