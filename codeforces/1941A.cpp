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
	int n, m, k;
	cin >> n >> m >> k;
	int b[n], c[m];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int j = 0; j < m; j++)
		cin >> c[j];

	sort(b, b + n);
	sort(c, c + m);

	int i = 0, j = m - 1;
	int ct = 0;
	while (i < n && j >= 0)
	{
		if (b[i] + c[j] > k)
			j--;
		else
		{
			ct += (j + 1);
			i++;
		}
	}

	cout << ct << endl;
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