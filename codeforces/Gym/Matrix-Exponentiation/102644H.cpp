#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define REP(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
const int M = 1e9+7;
const int N = 2e5+5;

struct Matrix{
    int mat[2][2];

    Matrix operator*(const Matrix &other){
        Matrix prod;
        REP(i,2) REP(j,2) REP(k,2){
            prod.mat[i][j] = (prod.mat[i][j] + (mat[i][k]*1LL*other.mat[k][j])%M)%M;
        }
        return prod;
    }

    Matrix(){
        mat[0][0]=mat[1][1]=mat[0][1]=mat[1][0]=0;
    }
};

Matrix getMat(char c){
    Matrix leaf;
    if(c=='?'){
        leaf.mat[0][0]=19;
        leaf.mat[0][1]=7;
        leaf.mat[1][0]=6;
        leaf.mat[1][1]=20;
    }
    else if(c=='S' || c=='D'){
        leaf.mat[0][0]=0;
        leaf.mat[0][1]=1;
        leaf.mat[1][0]=0;
        leaf.mat[1][1]=1;
    }
    else if(c=='H'){
        leaf.mat[0][0]=1;
        leaf.mat[0][1]=0;
        leaf.mat[1][0]=1;
        leaf.mat[1][1]=0;
    }
    else if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
        leaf.mat[0][0]=0;
        leaf.mat[0][1]=1;
        leaf.mat[1][0]=1;
        leaf.mat[1][1]=0;
    }
    else{
        leaf.mat[0][0]=1;
        leaf.mat[0][1]=0;
        leaf.mat[1][0]=0;
        leaf.mat[1][1]=1;
    }
    return leaf;
}

string s;
Matrix seg[4*N];

void build(int id, int l, int r){
    if(l>r) return;
    if(l==r){
        seg[id] = getMat(s[l]);
        return;
    }

    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    seg[id]=seg[id<<1]*seg[id<<1|1];
}

void update(int id, int l, int r, int i, char c){
    if(l>r || l>i || r<i) return;
    if(l==r){
        seg[id] = getMat(c);
        return;
    }

    int mid = (l+r)/2;
    update(id<<1,l,mid,i,c);
    update(id<<1|1,mid+1,r,i,c);
    seg[id]=seg[id<<1]*seg[id<<1|1];
}

int main()
{
    FASTIO
    int n,q;
    cin >> n >>q;
    cin >> s;

    build(1,0,n-1);

    cout << seg[1].mat[0][0]<<endl;
    while(q--){
        int i;
        char c;
        cin >> i >> c;
        update(1,0,n-1,i-1,c);
        cout << seg[1].mat[0][0]<<endl;
    }
}