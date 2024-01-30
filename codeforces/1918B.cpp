#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	int a[n], b[n];
	int pos[n + 1];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		pos[a[i]] = i;
	}
	for (int i = 0; i < n; i++)
		cin >> b[i];

	for (int i = 1; i <= n; i++)
		cout << i << " ";
	cout << endl;
	for (int i = 1; i <= n; i++)
		cout << b[pos[i]] << " ";
	cout << endl;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}