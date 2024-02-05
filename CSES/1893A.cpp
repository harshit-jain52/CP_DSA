#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

bool solve()
{
	int n, k;
	cin >> n >> k;

	int b[n];
	bool vis[n];

	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		vis[i] = false;
	}

	int pos = n - 1;
	while (k--)
	{
		if (b[pos] > n)
			return false;
		if (vis[pos])
			return true;

		vis[pos] = true;
		pos = (pos - b[pos] + n) % n;
	}

	return true;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		if (solve())
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}
}