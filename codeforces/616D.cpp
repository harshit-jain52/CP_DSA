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
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	map<int, int> m;
	int i = 0, j = 0;
	int len = 0;
	int idx = 0;

	while (j < n)
	{
		m[a[j]]++;

		while ((int)m.size() > k)
		{
			m[a[i]]--;
			if (m[a[i]] == 0)
				m.erase(a[i]);
			i++;
		}

		if (j - i + 1 > len)
		{
			len = j - i + 1;
			idx = i;
		}
		j++;
	}

	cout << idx + 1 << " " << idx + len;
}