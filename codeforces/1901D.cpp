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
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int left[n], right[n];
	left[0] = a[0];
	right[n - 1] = a[n - 1] + n - 1;
	for (int i = 1; i < n - 1; i++)
	{
		left[i] = max(left[i - 1], a[i] - i);
		right[n - i - 1] = max(right[n - i], a[n - i - 1] + n - i - 1);
	}

	int ans = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		int len1 = i, len2 = n - i - 1;

		int leftmax = (len1 != 0) ? left[i - 1] : -len2 - i;
		int rightmax = (len2 != 0) ? right[i + 1] : -len1 + i;
		ans = min(ans, max({a[i], leftmax + len2 + i, rightmax + len1 - i}));
	}

	cout << ans;
}