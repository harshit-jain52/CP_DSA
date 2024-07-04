#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+6;

bool sub[N], super[N];

void submasks(int num){
    if(sub[num]) return;
    sub[num]=true;
    
    for(int i=0;;i++){
        int pow = 1<<i;
        if(pow>num) return;
        if(pow&num) submasks(num-pow);
    }
}

void supermasks(int num){
   if(super[num]) return;
   super[num]=true;
   
   for(int i=0;;i++){
        int pow = 1<<i;
        if(pow+num>=N) return;
        if((pow&num)==0) supermasks(pow+num);
    }
}

int main(){
    int n,q; cin >> n>>q;
    while(n--){
        int a; cin >> a;
        submasks(a);
        supermasks(a);
    }
    
    while(q--){
        int x; cin >> x;
        if(sub[x] || super[x]) cout << "Yes\n";
        else cout << "No\n";
    }
}