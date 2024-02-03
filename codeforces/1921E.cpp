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
	ll xa, xb, h, ya, yb, w;
	cin >> h >> w >> xa >> ya >> xb >> yb;

	if (xa > xb)
	{
		cout << "Draw" << endl;
		return;
	}

	ll cover = xb - xa;
	if (cover % 2 == 1)
	{
		if (ya > yb)
		{
			ya--;
			yb = max(yb - cover / 2, 1LL);
			ya = max(ya - cover / 2, 1LL);
		}
		else if (ya < yb)
		{
			ya++;
			yb = min(yb + cover / 2, w);
			ya = min(ya + cover / 2, w);
		}

		if (ya == yb)
			cout << "Alice" << endl;
		else
			cout << "Draw" << endl;
		return;
	}
	else
	{
		if (ya > yb)
		{
			yb = max(yb - cover / 2, 1LL);
			ya = max(ya - cover / 2, 1LL);
		}
		else if (ya < yb)
		{
			yb = min(yb + cover / 2, w);
			ya = min(ya + cover / 2, w);
		}

		if (ya == yb)
			cout << "Bob" << endl;
		else
			cout << "Draw" << endl;
		return;
	}
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