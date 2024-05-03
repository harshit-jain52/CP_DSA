#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

vector<int> z_function(string &s)
{
	/*
	The Z-function for this string is an array of length n where the i-th element is equal to the greatest number of characters
	starting from the position i that coincide with the first characters of s.
	z[i] is the length of the longest string that is, at the same time, a prefix of s and a prefix of the suffix of s starting at i.
	*/

	int n = s.size();
	vector<int> z(n, 0);

	int l = 0, r = 0;

	// [l,r) indices of the rightmost segment match (substring coinciding with prefix of s)

	for (int i = 1; i < n; i++)
	{
		if (i < r)
			z[i] = min(r - i, z[i - l]);

		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;

		if (i + z[i] > r)
		{
			l = i;
			r = i + z[i];
		}
	}

	return z;
}

bool canDivide(int lcp, int k, vector<int> &z)
{
	int ct = 1;
	int n = z.size();

	for (int i = lcp; i < n;)
	{
		if (z[i] >= lcp)
		{
			ct++;
			i += lcp;
		}
		else
			i++;
	}

	return (ct >= k);
}

void solve()
{
	int n, l, r;
	cin >> n >> l >> r;
	string s;
	cin >> s;

	vector<int> z = z_function(s);
	int lo = 0, hi = n + 1;

	while (hi - lo > 1)
	{
		int mid = (lo + hi) / 2;
		if (canDivide(mid, l, z))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << endl;
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