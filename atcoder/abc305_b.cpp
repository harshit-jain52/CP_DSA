#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
	FASTIO
	char p,q;
	cin >> p >> q;

	vector<int>dist{0,3,4,8,9,14,23};
	cout << abs(dist[p-'A']-dist[q-'A']);
}