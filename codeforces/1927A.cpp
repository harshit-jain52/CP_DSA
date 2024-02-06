#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int start = -1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'B')
		{
			start = i;
			break;
		}
	}

	if (start == -1)
	{
		cout << 0 << endl;
		return;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == 'B')
		{
			cout << (i - start + 1) << endl;
			return;
		}
	}
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