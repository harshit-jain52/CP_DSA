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
	set<int> missing;
	map<int, int> freq;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		missing.insert(i);
	}
	missing.insert(n);

	int i = 0, j = 0;
	for (; j < i + m; j++)
	{
		freq[a[j]]++;
		if (missing.find(a[j]) != missing.end())
			missing.erase(a[j]);
	}

	int ans = *missing.begin();

	while (j < n)
	{
		if (--freq[a[i]] == 0)
			missing.insert(a[i]);
		freq[a[j]]++;
		if (missing.find(a[j]) != missing.end())
			missing.erase(a[j]);

		ans = min(ans, *missing.begin());
		i++;
		j++;
	}

	cout << ans;
}