#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

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

bool solve(){
	int n; cin >> n;
	map<int,int>pos;

	for(int i=0;i<n;i++){
		int a; cin >> a;
		pos[a] = i;
	}

	vector<int>arr(n);
	bool flag = true;
	for(int i=0;i<n;i++){
		int b; cin >> b;
		if(pos.find(b)==pos.end()) flag = false;
		arr[i]=pos[b];
	}

	if(!flag) return false;

	ll inv = inversions(arr);
	// cout << inv << endl;
	return (inv%2==0);
}

int main()
{
	FASTIO
	int t;
	cin >> t;
	while(t--){
		if(solve()) cout << "YES\n";
		else cout << "NO\n";
	}
}