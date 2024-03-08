#include <bits/stdc++.h>
using namespace std;
// #define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
	int n, t, k;
	cin >> n >> t;
	cin >> k;

	int lo = 1, hi = n;
	int l, r, len, ct = 0;
	int req = 20;
	while (req--)
	{
		l = lo, r = (lo + hi) / 2;
		len = r - l + 1;
		cout << "? " << l << " " << r << endl;
		int sum;
		cin >> sum;

		if (len == 1 && sum == 0 && ct == k - 1)
		{
			cout << "! " << r << endl;
			break;
		}
		if (len - sum + ct < k)
		{
			lo = r + 1;
			ct += len - sum;
		}
		else
			hi = r;
	}
}