#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned x, steps;

    cin >> x;

    bool more = (x % 5);

    steps = x / 5 + more;

    cout << steps;
    return 0;
}