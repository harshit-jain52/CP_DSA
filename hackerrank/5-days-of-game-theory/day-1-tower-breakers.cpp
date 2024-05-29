#include <iostream>
using namespace std;

int solve(){
    int n,m;
    cin >> n >> m;
    
    if(m==1 || n%2==0) return 2;
    return 1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
}