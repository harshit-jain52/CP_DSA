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
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> vec;
	for (int i = n; i >= 1; i--)
	{
		vec.push_back({i, 0});
	}

	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			char c;
			cin >> c;
			auto pp = vec.back();
			if (c == 'U')
				pp.second++;
			else if (c == 'D')
				pp.second--;
			else if (c == 'R')
				pp.first++;
			else
				pp.first--;

			vec.push_back(pp);
		}
		else
		{
			int p;
			cin >> p;
			auto coord = vec[vec.size() - p];
			cout << coord.first << " " << coord.second << endl;
		}
	}
}