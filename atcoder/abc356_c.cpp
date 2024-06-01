#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    int n,m,k;
    cin >> n >> m >> k;

    vector<pair<int,bool>>test(m);
    for(int i=0;i<m;i++){
        int c; cin >> c;
        int key = 0;
        while(c--){
            int a; cin >> a; a--;
            key |= (1<<a);
        }
        char res; cin >> res;
        test[i] = make_pair(key,(res=='o'));
        // cout << test[i].first<<" "<<test[i].second<<endl;
    }

    int ct = 0;
    for(int i=0;i<(1<<n);i++){
        int flag = 1;
        for(int j=0;j<m;j++){
            int tmp = __builtin_popcount(i&test[j].first);
            if(tmp<k) flag &= !test[j].second;
            else flag &= test[j].second;
        }
        if(flag) ct++;
    }
    cout << ct;
}