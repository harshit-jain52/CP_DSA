#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	int g,h,i,j,k,l;
	cin >> g >> h >> i >> j >> k >> l;


	bool flagx = max(a,g)<min(d,j);
	bool flagy = max(b,h)<min(e,k);
	bool flagz = max(c,i)<min(f,l);

	if(flagx && flagy && flagz) cout << "Yes";
	else cout << "No";
}