#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef unsigned long long ull;
const int M = 1e9 + 7;

void solve()
{
	ull n;
	int s;
	cin >> n >> s;
	string num = to_string(n);

	int sz = num.size();
	int digsum = 0;
	for (int i = 0; i < sz; i++)
	{
		digsum += (num[i] - '0');
	}

	if (digsum <= s)
	{
		cout << 0 << endl;
		return;
	}

	int idx = -1;
	digsum = 0;
	for (int i = 0; i < sz; i++)
	{
		digsum += (num[i] - '0');
		if (digsum >= s)
		{
			idx = i;
			break;
		}
	}

	ull toSubtract = 0;
	for (int i = idx; i < sz; i++)
	{
		toSubtract = toSubtract * 10 + (num[i] - '0');
	}
	// cout << toSubtract << endl;
	int pow = sz - idx;
	ull subFrom = 1;
	while (pow--)
		subFrom *= 10;
	cout << subFrom - toSubtract << endl;
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