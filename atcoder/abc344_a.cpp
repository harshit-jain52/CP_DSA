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
	int toggle = true;
	string t = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '|')
		{
			toggle = !toggle;
			continue;
		}
		if (toggle)
			t.push_back(s[i]);
	}
	cout << t;
}