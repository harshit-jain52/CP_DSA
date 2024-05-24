#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ll;
const int M = 1e9+7;

bitset<INT_MAX>st;
ll sum =0;

void insert(int num){
    if(st[num]) return;
    sum+=num;
    st[num]=true;
}

void remove(int num){
    if(!st[num]) return;
    sum -= num;
    st[num]=false;
}

int main()
{
    FASTIO
    int q;
    unsigned int si,a,b;
    cin >> q>>si >> a >> b;
    
    if(si&1) insert(si/2);
    else remove(si/2);
    q--;

    while(q--){
        si = si*a+b;
        if(si&1) insert(si/2);
        else remove(si/2);
    }

    cout << sum;
}