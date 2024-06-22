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
    int ct = 0;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        if(s=="Takahashi") ct++;
    }
    cout << ct;
}