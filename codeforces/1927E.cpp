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
	int n, k;
	cin >> n >> k;
	int arr[n + 1];
	int num = n;
	int start = 1;
	while (start <= k)
	{
		for (int i = start; i <= n; i += k)
		{
			arr[i] = num--;
		}
		start += 2;
	}

	num = 1;
	start = k;
	while (start > 0)
	{
		for (int i = start; i <= n; i += k)
		{
			arr[i] = num++;
		}
		start -= 2;
	}

	for (int i = 1; i <= n; i++)
		cout << arr[i] << " ";

	cout << endl;
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