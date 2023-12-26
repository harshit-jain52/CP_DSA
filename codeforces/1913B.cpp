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
	string s;
	cin >> s;
	int n = s.size();
	int ct0 = 0, ct1 = 0;

	for (int i = 0; i < n; i++)
	{
		ct0 += (s[i] == '0');
		ct1 += (s[i] == '1');
	}

	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0')
		{
			if (ct1 > 0)
				ct1--;
			else
			{
				cout << (n - i) << endl;
				return;
			}
		}
		else
		{
			if (ct0 > 0)
				ct0--;
			else
			{
				cout << (n - i) << endl;
				return;
			}
		}
	}

	cout << 0 << endl;
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