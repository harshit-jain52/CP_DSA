#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

int ct=0;
vector<bool>bad(26,false);
vector<vector<int>>trie(1,vector<int>(26));
vector<vector<bool>>mark(1,vector<bool>(26));

void insert(string s){
	int node = 0;
	int sz = s.size();

	for(int i=0;i<sz;i++){
		int c = s[i]-'a';
		if(!trie[node][c]){
			trie.push_back(vector<int>(26));
			mark.push_back(vector<bool>(26));
			trie[node][c] = trie.size()-1;
		}
		node = trie[node][c];
	}
}

void search(int node, int k){
	for(int c =0; c<26;c++){
		if(trie[node][c]){
			if(bad[c] && (k==0)) continue;

			if(!mark[node][c]){
				ct++;
				mark[node][c]=true;
			}

			search(trie[node][c],k-bad[c]);
		}
	}
}

int main()
{
	FASTIO
	string s;
	cin >> s;
	for(int i=0;i<26;i++){
		char c; cin >> c;
		bad[i]=(c=='0');
	}
	int k; cin >> k;

	int n = s.size();
	for(int i=0;i<n;i++) insert(s.substr(i,n-i));

	search(0,k);
	cout << ct;
}