#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    string s; cin >> s;
    if(s[0]=='R' || (s[1]=='R' && s[2]=='M')) cout << "Yes";
    else cout << "No";
}