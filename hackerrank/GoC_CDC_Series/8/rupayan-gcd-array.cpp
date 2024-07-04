#include <bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;
const int M = 1e9+7;
const int SZ=20;

int binpow(int a, int b){
    int ans = 1;
    while(b){
        if(b&1) ans = (ans*1LL*a)%M;
        a = (a*1LL*a)%M;
        b>>=1;
    }
    return ans;
}

class Matrix{
public:
    vector<vector<int>>mat;
    
    Matrix(){
        mat.assign(SZ,vector<int>(SZ,0));
    }
    
    Matrix operator=(const Matrix &other){
        mat = other.mat;
        return *this;
    }
    
    Matrix identity(){
        Matrix I;
        REP(i,SZ) I.mat[i][i]=1;
        return I;
    }
    
    Matrix operator*(const Matrix &other){
        Matrix prod;
        REP(i,SZ) REP(j,SZ) REP(k,SZ){
            prod.mat[i][j] = (prod.mat[i][j] + (mat[i][k]*1LL*other.mat[k][j])%M)%M;
        }
        return prod;
    }
    
    Matrix binExp(int n){
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

int main(){
    int n,m; cin >> n >> m;
    int ans = 1;
    
    while(m--){
        int l,r,g; cin >> l >> r >> g;
        int len = (r-l+1);
        n-=len;
        
        Matrix m;
        REP(i,SZ) REP(j,SZ) if(__gcd(i+1,j+1)==g) m.mat[i][j]=1;
        
        m = m.binExp(len-1);
        
        int ct = 0;
        REP(i,SZ) REP(j,SZ) ct = (ct+m.mat[i][j])%M;
        ans = (ans*1LL*ct)%M;
    }
    
    ans = (ans*1LL*binpow(20,n))%M;
    cout << ans;
}