#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

ll hw[1001][1001];
ll prefSum[1001][1001];

void reset()
{
	for (int i = 0; i <= 1000; i++)
	{
		for (int j = 0; j <= 1000; j++)
		{
			hw[i][j] = 0;
			prefSum[i][j] = 0;
		}
	}
}

void solve()
{
	reset();

	int n, q;
	cin >> n >> q;

	while (n--)
	{
		int h, w;
		cin >> h >> w;
		hw[h][w] += h * w;
	}

	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= 1000; j++)
		{
			prefSum[i][j] = hw[i][j] + prefSum[i][j - 1] + prefSum[i - 1][j] - prefSum[i - 1][j - 1];
		}
	}

	while (q--)
	{
		int hs, ws, hb, wb;
		cin >> hs >> ws >> hb >> wb;

		cout << prefSum[hb - 1][wb - 1] - prefSum[hb - 1][ws] - prefSum[hs][wb - 1] + prefSum[hs][ws] << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}