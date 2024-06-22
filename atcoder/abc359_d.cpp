#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 998244353;

int n,k;
string s;
int dp[1001][512];

bool canPlace(int mask, int c){
    if(((mask>>(k-2))&1) != c) return true;

    int i=0, j=k-3;
    while(i<j){
        if(((mask>>i)&1) != ((mask>>j)&1)) return true;
        i++;
        j--;
    }
    return false;
}

int func(int idx, int mask){
    if(idx==n) return 1;
    if(dp[idx][mask]!=-1) return dp[idx][mask];

    int ways=0;
    if(s[idx]!='B'){
        if(idx<k-1 || canPlace(mask,1)){
            int nmask = mask<<1;
            nmask&=((1<<(k-1))-1);
            nmask |= 1;
            ways += func(idx+1,nmask);
            ways%=M;
        }
    }
    if(s[idx]!='A'){
        if(idx<k-1 || canPlace(mask,0)){
            int nmask = mask<<1;
            nmask&=((1<<(k-1))-1);
            nmask |= 0;
            ways += func(idx+1,nmask);
            ways%=M;
        }
    }
    
    return dp[idx][mask] = ways;
}

int main()
{
    FASTIO
    memset(dp,-1,sizeof(dp));
    cin >> n >> k;
    cin >> s;

    if(k==1){
        cout << 0 << endl;
        return 0;
    }

    cout << func(0,0);
}