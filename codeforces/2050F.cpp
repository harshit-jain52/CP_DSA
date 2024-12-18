#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

const int N = 2e5 + 5;
const int LOG = 18;
int m[N][LOG];
int binLog[N];

int query(int L, int R)
{
	if(L>R) return 0;
    int k = binLog[R - L + 1];
    return __gcd(m[L][k], m[R - (1 << k) + 1][k]);
}

void solve(){
	int n,q; cin >> n >> q;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];

	binLog[1] = 0;
    for (int i = 2; i <= n; i++) binLog[i] = 1 + binLog[i / 2];

    for (int i = 0; i < n-1; i++) m[i][0] = abs(a[i+1]-a[i]);

    for (int j = 1; j <= binLog[n]; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            m[i][j] = __gcd(m[i][j - 1], m[i + (1 << (j - 1))][j - 1]);
        }
    }

    while(q--){
    	int l,r; cin >> l >> r;
    	l--; r--;
    	cout << query(l,r-1) << " ";
    }
    cout << endl;
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}