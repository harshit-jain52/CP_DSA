#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

bool canDivide(int lcp, int k, string &s)
{
	int curr = 0;
	int ct = 1;
	int n = s.size();
	bool fin;
	for (int i = lcp; i < n;)
	{
		while (i < n && s[i] != s[0])
			i++;
		fin = false;
		for (int j = i; j < min(n, i + lcp); j++)
		{
			if (s[j] != s[curr])
			{
				break;
			}

			curr++;
			if (curr == lcp)
			{
				ct++;
				i += lcp;
				fin = true;
				break;
			}
		}
		if (!fin)
			i++;
		curr = 0;
	}

	return (ct >= k);
}

void solve()
{
	int n, l, r;
	cin >> n >> l >> r;
	string s;
	cin >> s;

	int lo = 0, hi = n, mid;

	while (hi - lo > 1)
	{
		mid = (lo + hi) / 2;
		if (canDivide(mid, l, s))
			lo = mid;
		else
			hi = mid - 1;
	}
	if (canDivide(hi, l, s))
		cout << hi;
	else
		cout << lo;
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