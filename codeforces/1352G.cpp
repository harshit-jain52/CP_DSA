#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void solve()
{
	int n;
	cin >> n;
	if (n < 4)
	{
		cout << -1 << endl;
		return;
	}

	int num = n - (n % 2 == 0);
	while (num >= 1)
	{
		cout << num << " ";
		num -= 2;
	}

	cout << 4 << " " << 2 << " ";
	num = 6;
	while (num <= n)
	{
		cout << num << " ";
		num += 2;
	}

	cout << endl;
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