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
    cin >> n;
    string s;
    cin >> s;

    vector<int> vec(26, 0);
    vec[s[0] - 'a'] = 1;
    int ct = 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            ct++;
        else
            ct = 1;

        vec[s[i] - 'a'] = max(vec[s[i] - 'a'], ct);
    }

    int sum = 0;
    for (int i = 0; i < 26; i++)
        sum += vec[i];

    cout << sum;
}