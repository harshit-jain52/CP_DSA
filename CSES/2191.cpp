#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

class Point
{
public:
	ll x, y;
	Point(ll a = 0, int b = 0) : x(a), y(b) {}
	friend istream &operator>>(istream &in, Point &p)
	{
		in >> p.x >> p.y;
		return in;
	}
};

int main()
{
	FASTIO
	int n;
	cin >> n;
	vector<Point> points(n);

	for (int i = 0; i < n; i++)
		cin >> points[i];

	points.push_back(points[0]);

	ll areaTwice = 0;
	for (int i = 0; i < n; i++) // Shoelace Formula
		areaTwice += (points[i].x * points[i + 1].y) - (points[i].y * points[i + 1].x);

	cout << abs(areaTwice);
}