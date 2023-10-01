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
    set<int> s;
    int n;
    cin >> n;

    while (n--)
    {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    cout << s.size() << endl;
}