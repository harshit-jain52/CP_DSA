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
	int n, m, k;
	cin >> n >> m >> k;
	int a[n], b[m];
	vector<pair<bool, bool>> present(k + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] <= k)
			present[a[i]].first = true;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
		if (b[i] <= k)
			present[b[i]].second = true;
	}

	int ct_a = 0, ct_b = 0;

	for (int i = 1; i <= k; i++)
	{
		if (!present[i].first && !present[i].second)
			return false;
		if (present[i].first && present[i].second)
			continue;

		if (present[i].first)
		{
			ct_a++;
			if (ct_a > k / 2)
				return false;
		}
		else
		{
			ct_b++;
			if (ct_b > k / 2)
				return false;
		}
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
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
}