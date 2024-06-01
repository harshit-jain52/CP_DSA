#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    int n,m;
    cin >> n >> m;

    int a[m+1];
    for(int i=1;i<=m;i++) cin >> a[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin >> x;
            a[j]-=x;
        }
    }

    bool ans = true;
    for(int i=1;i<=m;i++){
        if(a[i]>0) ans = false;
    }

    if(ans) cout << "Yes";
    else cout << "No";
}