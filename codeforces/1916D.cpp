#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

string zeroes(int n){
    string s="";
    while(n--) s+='0';
    return s;
}

void solve(){
    int n;
    cin >> n;

    if(n==1){
        cout << 1<<endl;
    }
    else{
        cout << "196" + zeroes(n-3) << endl;

        for(int i=0;i<=(n-3)/2;i++){
            cout << "1"+zeroes(i)+"6"+zeroes(i)+"9"+zeroes(n-3-2*i) << endl;
            cout << "9"+zeroes(i)+"6"+zeroes(i)+"1"+zeroes(n-3-2*i) << endl;
        }
    }
}

int main()
{
    FASTIO
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}