#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int main()
{
    FASTIO
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>>vec;

    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        vec.push_back({a,1});
    }

    for(int i=0;i<m;i++){
        int b;
        cin >> b;
        vec.push_back({b,2});
    }

    sort(vec.begin(),vec.end());

    for(int i=1;i<vec.size();i++){
        if(vec[i].second == 1 && vec[i-1].second==1){
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
}