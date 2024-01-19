#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
	FASTIO
	int q;
	cin >> q;
	map<int, int> lct, rct;
	while (q--)
	{
		char c;
		int l, r;
		cin >> c >> l >> r;
		if (c == '+')
		{
			lct[-l]++;
			rct[r]++;
		}
		else
		{
			lct[-l]--;
			rct[r]--;
			if (lct[-l] == 0)
				lct.erase(-l);
			if (rct[r] == 0)
				rct.erase(r);
		}

		if (-(*lct.begin()).first > (*rct.begin()).first)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}