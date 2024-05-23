#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define REP(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
const int M = 1e9+7;

class Matrix{
public:
    vector<vector<int>>mat;
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
    int n;
    ll k;
    cin >> n >> k;
    int a[n],c[n],p,q,r;
    REP(i,n) cin >> a[i];
    REP(i,n) cin >> c[i];
    cin >> p >> q >> r;

    if(k<n){
        cout << a[k];
        return 0;
    }

    Matrix m(n+3);
    REP(i,n) m.mat[0][i] = c[i];
    m.mat[0][n]=r; m.mat[0][n+1]=q, m.mat[0][n+2]=p;

    REP(j,n-1) m.mat[j+1][j]=1;

    m.mat[n][n]=m.mat[n][n+2]=m.mat[n+1][n+1]=m.mat[n+1][n+2]=m.mat[n+2][n+2]=1;
    m.mat[n][n+1]=2;
    
    Matrix res = m.binExp(k-n+1);

    int ans = 0;
    REP(i,n) ans = ((ans + (res.mat[0][i]*1LL*a[n-1-i])%M))%M;
    ans = (ans + (res.mat[0][n]*1LL*((n*1LL*n)%M))%M)%M;
    ans = (ans + (res.mat[0][n+1]*1LL*n)%M)%M;
    ans = (ans + res.mat[0][n+2])%M;
    cout << ans;
}