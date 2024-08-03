#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;


int main()
{
	FASTIO
	string str; cin >> str;
    str += '$';
    const int n = str.size();

    vector<pair<pair<int, int>, int>> suffs(n);
    for (int i=0; i<n; i++) suffs[i] = {{str[i], str[i]}, i};
    
    sort(suffs.begin(), suffs.end());
    vector<int> equiv(n);

    for (int i=1; i<n; i++){
        auto [c_val, cs] = suffs[i];
        auto [p_val, ps] = suffs[i - 1];
        equiv[cs] = equiv[ps] + (c_val > p_val);
    }

    for (int cmp_amt = 1; cmp_amt < n; cmp_amt *= 2){
        for (auto &[val, s] : suffs) val = {equiv[s], equiv[(s + cmp_amt) % n]};

        sort(suffs.begin(), suffs.end());
        for (int i = 1; i < n; i++){
            auto [c_val, cs] = suffs[i];
            auto [p_val, ps] = suffs[i - 1];
            equiv[cs] = equiv[ps] + (c_val > p_val);
        }
    }

    for (int i=0; i<n; i++) cout << suffs[i].second << " ";
}

// O(Nlog^2N)