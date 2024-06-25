#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int n,m; cin >> n >> m;
	int a[n],b[m];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];

	int i=0, ct=0;
	for(int j=0;j<m;j++){
		while(i<n && a[i]<b[j]){
			i++;
			ct++;
		}
		cout << ct << " ";
	}
}