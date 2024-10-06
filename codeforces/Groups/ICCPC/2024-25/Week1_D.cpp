#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

vector<vector<int>> trie(1,vector<int>(10));
vector<int>ct(1);

vector<int>runes = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

void insert(string &s){
	int node = 0;
	ct[0]++;
	for(char c: s){
		int x = runes[c-'a'];
		if(!trie[node][x]){
			trie.push_back(vector<int>(10));
			ct.push_back(0);
			trie[node][x] = trie.size()-1;
		}
		node = trie[node][x];
		ct[node]++;
	}
}

int count(string &num){
	int node = 0;
	for(char c: num){
		int x = c-'0';
		if(x==0 || x==1 || !trie[node][x]) return 0;
		node = trie[node][x];
	}
	return ct[node];
}

int main()
{
	FASTIO
	int n, m;
	cin >> n >> m;

	for(int i=0;i<n;i++){
		string s; cin >> s;
		insert(s);
	}

	for(int i=0;i<m;i++){
		string num; cin >> num;
		cout << count(num) << endl;
	}
}