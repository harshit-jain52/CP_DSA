#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow27[7];
map<ll,int>ct;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    pow27[0]=1;
    for(int i=1;i<7;i++) pow27[i]=27*pow27[i-1];

    int n,m;
    cin >> n >> m;
    vector<string>str(n);
    for(int i=0;i<n;i++) cin >> str[i];

    for(int i=0;i<n;i++){
        string s = str[i];
        for(int mask=0;mask<(1<<m);mask++){
            ll num=0;
            for(int bit=0;bit<m;bit++){
                if((mask>>bit)&1) num += (s[bit]-'a'+1)*pow27[bit];
            }
            ct[num]++;
        }
    }

    int q; cin >> q;
    while(q--){
        string s; cin >> s;
        ll num = 0;
        for(int bit=0;bit<m;bit++){
            if(s[bit]!='?') num += (s[bit]-'a'+1)*pow27[bit];
        }
        cout << ct[num] << endl;
    }
}