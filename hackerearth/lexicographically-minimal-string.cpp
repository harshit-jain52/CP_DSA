#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef pair<int,int> pii;
const int M = 1e9+7;

pii par[26];

pii find(int v){
    if(v!=par[v].first){
        int tmp = par[v].second;
        par[v] = find(par[v].first);
        par[v].second = min(par[v].second,tmp);
    }
    return par[v];
}

void Union(int u, int v){
    pii pu = find(u), pv = find(v);

    if(pu.first==pv.first) return;
    if(pu.second > pv.second) swap(pu,pv);
    par[pv.first] = make_pair(pu.first,pu.second);
}

int main()
{
    FASTIO
    string a,b,c;
    cin >> a>> b >> c;

    for(int i=0;i<26;i++) par[i]=make_pair(i,i);

    int n = a.size();
    for(int i=0;i<n;i++){
        Union(a[i]-'a',b[i]-'a');
    }

    int m = c.size();
    for(int i=0;i<m;i++){
        c[i] = 'a' + find(c[i]-'a').second;
    }
    cout << c;
}

/*
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/lexicographically-minimal-string-6edc1406/description/
*/
