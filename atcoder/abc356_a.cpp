#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    int n,l,r;
    cin >> n >> l >> r;

    for(int i=1;i<=l-1;i++) cout << i << " ";
    for(int i=r;i>=l;i--) cout << i << " ";
    for(int i=r+1;i<=n;i++) cout << i << " ";
}