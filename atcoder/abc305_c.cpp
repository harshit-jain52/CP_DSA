#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int h,w; cin >> h >> w;

	vector<string>grid(h);
	for(int i=0;i<h;i++) cin >> grid[i];

	int a=INT_MAX,b=INT_MIN,c=INT_MAX,d=INT_MIN;
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(grid[i][j]=='#'){
				a = min(a,i);
				b = max(b,i);
				c = min(c,j);
				d = max(d,j);
			}
		}
	}

	for(int i=a;i<=b;i++){
		for(int j=c;j<=d;j++){
			if(grid[i][j]!='#'){
				cout << i+1 << " "<<j+1;
				break;	
			}
		}
	}
}