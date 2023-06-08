#include <bits/stdc++.h>
using namespace std;

int lcm(int x, int y)
{
    return (x * y) / __gcd(x, y);
}

int main()
{
    int a, b, c, d, g1, g2, l, f1, f2, p, q, g3;
    cin >> a >> b >> c >> d;

    g1 = __gcd(a, b);
    g2 = __gcd(c, d);

    a = a / g1;
    b = b / g1;
    c = c / g2;
    d = d / g2;

    l = lcm(min(a, b), max(c, d));

    f1 = l / min(a, b);
    a = a * f1;
    b = b * f1;

    f2 = l / max(c, d);
    c = c * f2;
    d = d * f2;

    q = a * b;
    p = a * b - c * d;
    g3 = __gcd(p, q);

    cout << p / g3 << "/" << q / g3;
}