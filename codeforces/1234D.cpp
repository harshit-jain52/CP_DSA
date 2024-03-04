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
	int n = s.size(), q;
	cin >> q;
	set<int> arr[26];

	for (int i = 0; i < n; i++)
		arr[s[i] - 'a'].insert(i + 1);

	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int pos;
			char c;
			cin >> pos >> c;
			auto it = arr[s[pos - 1] - 'a'].find(pos);
			if (it != arr[s[pos - 1] - 'a'].end())
				arr[s[pos - 1] - 'a'].erase(it);
			s[pos - 1] = c;
			arr[s[pos - 1] - 'a'].insert(pos);
		}
		else
		{
			int ct = 0;
			int l, r;
			cin >> l >> r;
			for (int i = 0; i < 26; i++)
			{
				auto it = arr[i].lower_bound(l);
				if (it != arr[i].end() && *it <= r)
					ct++;
			}
			cout << ct << endl;
		}
	}
}