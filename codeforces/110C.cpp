#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e6 + 5;

int main()
{
	FASTIO
	int n;
	cin >> n;
	int num = -1;
	for (int i = 0; i <= n / 4; i++)
	{
		if ((n - i * 4) % 7 == 0)
		{
			num = i;
			break;
		}
	}

	if (num == -1)
		cout << -1;
	else
	{
		for (int i = 0; i < num; i++)
			cout << 4;
		for (int i = 0; i < (n - num * 4) / 7; i++)
			cout << 7;
	}
}