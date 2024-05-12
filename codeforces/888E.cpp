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
	int n, m;
	cin >> n >> m;
	int a[n];
	vector<int> half1, half2;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] %= m;
		if (i & 1)
			half1.push_back(a[i]);
		else
			half2.push_back(a[i]);
	}

	if (n == 1)
	{
		cout << a[0];
		return 0;
	}

	vector<int> sums1, sums2;
	int sz1 = half1.size(), sz2 = half2.size();

	for (int num = 0; num < (1 << sz1); num++)
	{
		int sum = 0;
		for (int i = 0; i < sz1; i++)
		{
			if ((1 << i) & num)
				sum = (sum + half1[i]) % m;
		}
		sums1.push_back(sum);
	}

	for (int num = 0; num < (1 << sz2); num++)
	{
		int sum = 0;
		for (int i = 0; i < sz2; i++)
		{
			if ((1 << i) & num)
				sum = (sum + half2[i]) % m;
		}
		sums2.push_back(sum);
	}

	sort(sums1.begin(), sums1.end());
	sort(sums2.begin(), sums2.end());
	int ans = 0;
	for (int s : sums1)
	{
		ans = max(ans, (s + sums2[sums2.size() - 1]) % m);
		auto it = lower_bound(sums2.begin(), sums2.end(), m - s);
		if (it != sums2.begin())
		{
			it--;
			ans = max(ans, s + (*it));
		}
	}

	cout << ans;
	return 0;
}