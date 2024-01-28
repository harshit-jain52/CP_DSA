#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
	int n;
	cin >> n;
	int m = 0;
	while ((1 << m) <= n - 1)
		m++;

	cout << m << endl;

	for (int i = 0; i < m; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < n; j++)
		{
			if ((1 << i) & j)
				tmp.push_back(j);
		}
		cout << tmp.size() << " ";
		for (int j : tmp)
			cout << j + 1 << " ";
		cout << endl;
	}

	string s;
	cin >> s;
	int bottle = 0;
	for (int i = 0; i < m; i++)
	{
		if (s[i] == '1')
			bottle += (1 << i);
	}

	cout << bottle + 1 << endl;
}