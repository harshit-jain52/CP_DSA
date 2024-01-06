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
	int n;
	cin >> n;

	int arr[n + 1][n + 1];
	int num = 1;
	arr[(n + 1) / 2][(n + 1) / 2] = 0;

	int i = 1, j = 1;
	int left = 1, right = n, up = 2, down = n;

	int dir = 0;
	while (num <= n * n - 1)
	{
		if (dir % 4 == 0) // right
		{
			arr[i][j] = num++;
			if (j == right)
			{
				i++;
				right--;
				dir++;
			}
			else
				j++;
		}
		else if (dir % 4 == 1) // down
		{
			arr[i][j] = num++;

			if (i == down)
			{
				j--;
				down--;
				dir++;
			}
			else
				i++;
		}
		else if (dir % 4 == 2) // left
		{
			arr[i][j] = num++;

			if (j == left)
			{
				i--;
				left++;
				dir++;
			}
			else
				j--;
		}
		else // up
		{
			arr[i][j] = num++;

			if (i == up)
			{
				j++;
				up++;
				dir++;
			}
			else
				i--;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j && i == (n + 1) / 2)
				cout << 'T' << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}