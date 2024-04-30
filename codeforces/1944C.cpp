#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

int solve()
{
	int n;
	cin >> n;
	vector<int> ct(n, 0);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		ct[a]++;
	}

	bool check = false;
	for (int i = 0; i < n; i++)
	{
		if (ct[i] == 0)
			return i;
		if (ct[i] == 1)
		{
			if (check)
				return i;
			else
				check = true;
		}
	}
	return n;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while (t--)
	{
		cout << solve() << endl;
	}
}