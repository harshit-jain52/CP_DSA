#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll merge(int l, int r, vector<int>&arr){
    int mid = (l+r)/2;
    vector<int>left,right;
    for(int i=l;i<=mid;i++) left.push_back(arr[i]);
    for(int i=mid+1;i<=r;i++) right.push_back(arr[i]);

    int n = left.size(), m = right.size();
    int i=0,j=0,k=l;

    ll ct=0;

    while(i<n && j<m){
        if(left[i]>right[j]){
            ct += n-i;
            arr[k]=right[j];
            j++;
        }
        else{
            arr[k]=left[i];
            i++;
        }
        k++;
    }

    while(i<n) arr[k++] = left[i++];
    while(j<m) arr[k++] = right[j++];

    return ct;
}

ll divide(int l, int r, vector<int>&arr){
    if(l>=r) return 0;
    ll ct = 0;
    int mid = (l+r)/2;
    ct += divide(l,mid,arr);
    ct += divide(mid+1,r,arr);
    ct += merge(l,r,arr);
    return ct;
}

ll inversions(vector<int>&arr){
    int n = arr.size();
    return divide(0,n-1,arr);
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> arr(n);
    vector<int>pref(n+1);
    pref[0]=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1') arr[i]=-1;
        else arr[i]=1;

        pref[i+1]=pref[i]+arr[i];
    }
    cout << inversions(pref) << endl;
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}