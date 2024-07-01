#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    string s,t;
    cin >> s >> t;

    bool flag = false;
    int n = s.size();
    for(int w=1;w<n;w++){
        for(int c=1;c<=w;c++){
            string tmp="";
            for(int i=0;i<n;i+=w){
                if(i+c-1<n) tmp+=s[i+c-1];
            }
            if(tmp==t) flag = true;
        }
    }

    if(flag) cout << "Yes";
    else cout << "No";
}