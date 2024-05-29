#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int solve(){
    string s;
    cin >> s;

    if(s=="0001" || s=="0010" || s=="0100" || s=="1000") return 11;
    if(s=="1100" || s=="0011") return 21;
    if(s=="1001" || s=="1010" || s=="0110" || s=="0101") return 121;
    if(s=="1111") return 441;
    return 231;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while(t--){
        cout << solve()<<endl;
    }
}