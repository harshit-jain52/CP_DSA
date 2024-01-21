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
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> a(n + 1, 0);
	multiset<int> lower, higher;
	for (int i = 0; i < k; i++)
		higher.insert(0);
	for (int i = 0; i < n - k; i++)
		lower.insert(0);

	ll sum = 0;

	while (q--)
	{
		int x, y;
		cin >> x >> y;

		int tmp = *(higher.begin());
		if (a[x] >= tmp)
		{
			sum -= a[x];
			auto it = higher.find(a[x]);
			higher.erase(it);

			int num = -(*(lower.begin()));
			if (num > y)
			{
				sum += num;
				auto it = lower.begin();
				lower.erase(it);
				higher.insert(num);
				lower.insert(-y);
			}
			else
			{
				sum += y;
				higher.insert(y);
			}
		}
		else
		{
			auto it = lower.find(-a[x]);
			lower.erase(it);

			if (y > tmp)
			{
				sum -= tmp;
				lower.insert(-tmp);
				auto it = higher.begin();
				higher.erase(it);
				sum += y;
				higher.insert(y);
			}
			else
			{
				lower.insert(-y);
			}
		}

		a[x] = y;
		cout << sum << endl;
	}
}