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

    int n, k;
    string s;
    cin >> n >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        int num = 0;
        for (int j = 0; j < k; j++)
        {
            if (s[j] == '1')
                num += (1 << j);
        }
        vec[i] = num;
    }

    int hamming = k;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            hamming = min(hamming, __builtin_popcount(vec[i] ^ vec[j]));

    cout << hamming;
}