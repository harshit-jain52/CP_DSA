#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	int D[21];
	D[1] = 0;
	D[2] = 1;

	for(int i=3;i<=20;i++) D[i] = ((i-1)*1LL*((D[i-1]+D[i-2])%M))%M;

	int n; cin >> n;
	cout << D[n];
}