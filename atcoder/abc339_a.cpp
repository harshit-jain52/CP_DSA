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
	string s;
	cin >> s;
	int i;
	for (i = s.size(); i >= 0; i--)
	{
		if (s[i] == '.')
			break;
	}

	for (i += 1; i < s.size(); i++)
	{
		cout << s[i];
	}
}