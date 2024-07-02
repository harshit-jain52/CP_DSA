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
    string s(n+1,'-');

    for(int j=1;j<=9;j++){
        if(n%j!=0) continue;
        int x = n/j;

        for(int i=0;i<=n;i++){
            if(i%x==0 && s[i]=='-') s[i]='0'+j;
        }
    }

    cout << s;
}