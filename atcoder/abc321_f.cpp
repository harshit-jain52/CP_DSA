#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 998244353;

int main()
{
	FASTIO
	int q,k;
	cin >> q >> k;
	vector<int>ct(k+1,0);
	ct[0]=1;
	while(q--){
		char type;
		int x;
		cin >> type >> x;
		if(type=='+'){
			for(int i=k;i>=x;i--) ct[i]=(ct[i]+ct[i-x])%M;
		}
		else{
			for(int i=x;i<=k;i++) ct[i]=(ct[i]-ct[i-x]+M)%M;
		}
		cout << ct[k]<<endl;
	}
}