#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

vector<int>kmp(string s){
    int n = s.length();
    vector<int>lps(n+1);
    
    int i=0,j=-1;
    lps[0]=-1;

    while(i<n){
        while(j!=-1 && s[i]!=s[j]) j = lps[j];
        lps[++i]= ++j;
    }

    return lps;
}

int main()
{
	FASTIO
	string s; cin >> s;
	int len = s.length();
    string t = s;
    reverse(t.begin(),t.end());

    vector<int> lps = kmp(t+'#'+s);
    int add = len-lps[2*len+1];

    cout << (s+t.substr(len-add,add));
}