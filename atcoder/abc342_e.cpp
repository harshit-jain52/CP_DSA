#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef unsigned long long ll;
const int M = 1e9 + 7;
const ll INF = LONG_LONG_MAX;
class Info
{
public:
	ll l_, d_, k_, c_;
	int A_;

	Info(ll l, ll d, ll k, ll c, int A) : l_(l), d_(d), k_(k), c_(c), A_(A) {}
};

int main()
{
	FASTIO
	int n, m;
	cin >> n >> m;

	vector<Info> graph[n + 1];

	while (m--)
	{
		ll l, d, k, c;
		int A, B;
		cin >> l >> d >> k >> c >> A >> B;
		graph[B].push_back(Info(l, d, k, c, A));
	}

	vector<ll> time(n + 1, 0);
	vector<bool> vis(n + 1, false);
	time[n] = INF;

	priority_queue<pair<ll, int>> pq;
	pq.push({INF, n});

	while (!pq.empty())
	{
		auto node = pq.top();
		pq.pop();
		int v = node.second;

		if (vis[v])
			continue;
		vis[v] = true;

		for (Info e : graph[v])
		{
			int next = e.A_;
			if (time[v] < e.c_ || time[v] - e.c_ < e.l_)
				continue;
			ll k = min(e.k_ - 1, (time[v] - e.c_ - e.l_) / e.d_);
			ll t = e.l_ + k * e.d_;
			if (t > time[next])
			{
				time[next] = t;
				pq.push({t, next});
			}
		}
	}

	for (int i = 1; i <= n - 1; i++)
	{
		if (time[i])
			cout << time[i] << endl;
		else
			cout << "Unreachable" << endl;
	}
}