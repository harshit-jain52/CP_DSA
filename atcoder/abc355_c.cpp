#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 2001;
int row[N*N],col[N*N];

int main()
{
    FASTIO
    int n,t;
    cin >> n >> t;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int num = n*(i-1) + j;
            row[num] = i;
            col[num] = j;
        }
    }

    vector<int>rowct(n+1,0),colct(n+1,0);
    int diag1=0,diag2=0;

    int a[t];
    for(int i=0;i<t;i++) cin >> a[i];

    for(int i=0;i<t;i++){
        int x = row[a[i]], y = col[a[i]];
        rowct[x]++; colct[y]++;
        if(x==y) diag1++;
        if(x+y==n+1) diag2++;

        if(rowct[x]==n || colct[y]==n || diag1==n || diag2==n){
            cout << (i+1);
            return 0;
        }
    }

    cout << -1;
}