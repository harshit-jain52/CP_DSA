#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    double p;
    cin >> n >> p;

    /*
    p2 = p1(1-p1) + (1-p1)p1
    p4 = p2(1-p2) + (1-p2)p2
    p8 = p4(1-p4) + (1-p4)p4
    .
    .
    (pi = mood flipped after i seconds)
    */

    double prob = 1.0;
    while (n > 0)
    {
        if (n % 2 == 1)
            prob = prob * (1 - p) + (1 - prob) * p;

        p = p * (1 - p) + (1 - p) * p;
        n /= 2;
    }

    printf("%.8f", prob);
}