#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

bool solve()
{
	int n;
	cin >> n;
	int b[n], dp[n];
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		dp[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		if (i + b[i] < n)
			dp[i + b[i]] |= (i == 0 || dp[i - 1]);
		if (i - b[i] >= 0)
			dp[i] |= (i - b[i] == 0 || dp[i - b[i] - 1]);
	}

	return dp[n - 1];
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
		if (solve())
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
}