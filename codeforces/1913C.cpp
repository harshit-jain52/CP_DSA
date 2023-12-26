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

	int m;
	cin >> m;
	vector<int> vec(30, 0);
	while (m--)
	{
		int type, v;
		cin >> type >> v;
		if (type == 1)
		{
			vec[v]++;
		}
		else
		{
			vector<int> ct = vec;
			vector<int> num(30, 0);

			bool isPossible = true;
			for (int i = 0; i < 30; i++)
			{
				if ((1 << i) & v)
					num[i]++;

				if (num[i] > ct[i])
				{
					isPossible = false;
					break;
				}

				if (i < 29)
					ct[i + 1] += (ct[i] - num[i]) / 2;
			}

			if (isPossible)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}