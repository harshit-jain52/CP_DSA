#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
#define F first
#define S second

void solve(){
    int n; cin >> n;
    vector<string>name(n);
    vector<pii>data(n);

    for(int i=0;i<n;i++){
        cin >> name[i] >> data[i].F;
        data[i].S=i;
    }

    sort(data.begin(),data.end());

    for(int i=0;i<n-1;){
        if(i==n-1) break;

        if(data[i+1].F-data[i].F<=2){
            cout << name[data[i].S] << " "<<name[data[i+1].S]<<endl;
            i+=2;
        }
        else i++;
    }
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}