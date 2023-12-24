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
	int n;
	cin >> n;

	int minX = 0, minY = 0, maxX = 0, maxY = 0;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		minX = min(minX, x);
		minY = min(minY, y);
		maxX = max(maxX, x);
		maxY = max(maxY, y);
	}

	return (minX == 0 || minY == 0 || maxX == 0 || maxY == 0);
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		if (solve())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}