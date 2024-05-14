#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;
const int N = 1e6 + 1;
vector<int> divis[N];
vector<int> freq(N, 0);
int main()
{
	FASTIO

	for (int i = 1; i < N; i++)
		for (int j = i; j < N; j += i)
			divis[j].push_back(i);

	int n;
	cin >> n;
	int x[n];
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		for (int d : divis[x[i]])
			freq[d]++;
	}

	ll suff[N];
	for (int i = N - 1; i >= 1; i--)
	{
		suff[i] = (freq[i] * 1LL * (freq[i] - 1)) / 2;
		for (int j = 2 * i; j < N; j += i)
		{
			suff[i] -= suff[j];
		}
	}

	cout << suff[1];
}