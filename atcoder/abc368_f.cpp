#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;
const int N = 1e5+5;

int sp[N];
int gr[N];

void sieve(){
	for(int i=2;i<N;i++) sp[i]=i;

	for(int i=2;i<N;i++){
		if(sp[i]==i){
			for(int j=2*i;j<N;j+=i) sp[j] = min(sp[j],i);
		}
	}
}

void grundy(){
	for(int i=1;i<N;i++){
		gr[i]=0;

		int num = i;
		while(num>1){
			int p = sp[num];
			while(num%p==0){
				num/=p;
				gr[i]++;
			}
		}
	}
}

int main()
{
	FASTIO
	sieve();
	grundy();

	int n; cin >> n;
	int x = 0;

	for(int i=0;i<n;i++){
		int a; cin >> a;
		x^=gr[a];
	}

	cout << ((x)?"Anna":"Bruno");
}