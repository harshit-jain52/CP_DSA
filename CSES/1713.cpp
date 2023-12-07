#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
vector<int> divis(N, 1);

void divisors()
{
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            divis[j]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    divisors();

    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cout << divis[x] << endl;
    }
}