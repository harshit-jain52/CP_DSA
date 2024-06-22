#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    int n; cin >> n;
    int a[2*n];
    for(int i=0;i<2*n;i++) cin >> a[i];

    int ct = 0;
    
    for(int i=2;i<2*n;i++) ct += (a[i]==a[i-2]);

    cout << ct;
}