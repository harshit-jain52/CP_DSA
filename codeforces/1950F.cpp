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
	int a, b, c;
	cin >> a >> b >> c;
	int h = 0;
	int curr = 1, next = 0;

	while (a)
	{
		a--;
		curr--;
		next += 2;

		if (curr == 0)
		{
			curr = next;
			next = 0;
			h++;
		}
	}

	while (b)
	{
		b--;
		curr--;
		next++;

		if (curr == 0)
		{
			curr = next;
			next = 0;
			h++;
		}
	}

	int l = curr + next;
	if (l != c)
		return -1;
	return (h + (next != 0));
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