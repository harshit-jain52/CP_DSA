#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int a,b; cin >> a >> b;

	for(int i=1;i<=9;i++){
		cout << ((a*b*i) + 9)/10 << " ";
	}
}