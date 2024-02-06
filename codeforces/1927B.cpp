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
	int a[n];
	string s;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s.push_back('*');
	}
	vector<int> alpha(26, -1);

	for (int i = 0; i < n; i++)
	{
		for (int c = 0; c < 26; c++)
		{
			if (alpha[c] == a[i] - 1)
			{
				alpha[c]++;
				s[i] = ('a' + c);
				break;
			}
		}
	}

	cout << s << endl;
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