#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define REP(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
const int M = 1e9+7;
const int LOG=31;

class Matrix{
public:
    vector<vector<int>>mat;
    Matrix(){}
    Matrix(int sz){
        mat.assign(sz,vector<int>(sz,0));
    }
    
    Matrix operator=(const Matrix &other){
        mat = other.mat;
        return *this;
    }

    Matrix identity(){
        int sz = mat.size();
        Matrix I(sz);
        REP(i,sz) I.mat[i][i]=1;
        return I;
    }

    Matrix operator*(const Matrix &other){
        int sz = mat.size();
        Matrix prod(sz);
        REP(i,sz) REP(j,sz) REP(k,sz){
            prod.mat[i][j] = (prod.mat[i][j] + (mat[i][k]*1LL*other.mat[k][j])%M)%M;
        }
        return prod;
    }

    Matrix binExp(ll n){
        Matrix ans = identity();
        Matrix a = *this;
        while(n){
            if(n&1) ans = ans*a;
            a = a*a;
            n>>=1;
        }
        return ans;
    }
};

int main()
{
    FASTIO
    int n,m,q;
    cin >> n >> m >> q;
    Matrix adj(n);

    while(m--){
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj.mat[a][b]++;
    }

    Matrix adj_pow[LOG];
    adj_pow[0] = adj;
    REP(p,LOG-1) adj_pow[p+1] = adj_pow[p]*adj_pow[p];

    while(q--){
        int s,t,k;
        cin >> s >> t >> k;
        s--;t--;

        vector<int>dp(n,0);
        dp[s]++;

        for(int bit=0; (1<<bit)<=k;bit++){
            if(k&(1<<bit)){
                vector<int>dp2(n,0);
                REP(i,n) REP(j,n){
                    dp2[j] = (dp2[j] + (dp[i]*1LL*adj_pow[bit].mat[i][j])%M)%M;
                }
                dp=dp2;
            }
        }

        cout << dp[t]<<endl;
    }
}