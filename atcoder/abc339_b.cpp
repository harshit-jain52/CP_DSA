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
	int h, w, n;
	cin >> h >> w >> n;

	vector<vector<char>> grid(h, vector<char>(w, '.'));

	char move = 'u';
	int i = 0, j = 0;
	while (n--)
	{
		if (grid[i][j] == '.')
		{
			grid[i][j] = '#';

			if (move == 'u')
			{
				j = (j + 1) % w;
				move = 'r';
			}
			else if (move == 'r')
			{
				i = (i + 1) % h;
				move = 'd';
			}
			else if (move == 'd')
			{
				j = (j - 1 + w) % w;
				move = 'l';
			}
			else
			{
				i = (i - 1 + h) % h;
				move = 'u';
			}
		}
		else
		{
			grid[i][j] = '.';

			if (move == 'd')
			{
				j = (j + 1) % w;
				move = 'r';
			}
			else if (move == 'l')
			{
				i = (i + 1) % h;
				move = 'd';
			}
			else if (move == 'u')
			{
				j = (j - 1 + w) % w;
				move = 'l';
			}
			else
			{
				i = (i - 1 + h) % h;
				move = 'u';
			}
		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << grid[i][j];
		}
		cout << endl;
	}
}