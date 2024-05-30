#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

bool solve(){
    int n; string s;
    cin >> n; cin >> s;

    int lastlet='a',lastdig='0';
    for(int i=0;i<n;i++){
        if(s[i]>='0' && s[i]<='9'){
            if(s[i]<lastdig) return false;
            if(i>0 && s[i-1]==lastlet) return false;
            lastdig=s[i];
        }
        else{
            if(s[i]<lastlet) return false;
            lastlet=s[i];
        }
    }
    return true;
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while(t--){
        if(solve()) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}