#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
const int M = 1e9+7;

string steps;
bool vis[7][7];

inline bool canGo(int x, int y){
	return (x>=0 && y>=0 && x<7 && y<7 && !vis[x][y]);
}

int ways(int idx, int i, int j, char dir){
	if(idx==48) return (i==6 && j==0);
	if(i==6 && j==0) return 0;

	// hitting a wall or path
	if(dir=='U') if((i==0 || vis[i-1][j]) && canGo(i,j-1) && canGo(i,j+1)) return 0;
	if(dir=='D') if((i==6 || vis[i+1][j]) && canGo(i,j-1) && canGo(i,j+1)) return 0;
	if(dir=='R') if((j==6 || vis[i][j+1]) && canGo(i-1,j) && canGo(i+1,j)) return 0;
	if(dir=='L') if((j==0 || vis[i][j-1]) && canGo(i-1,j) && canGo(i+1,j)) return 0;
	
	int ct =0;
	vis[i][j]=true;

	if(steps[idx]!='?'){
		if(steps[idx]=='U' && canGo(i-1,j)) ct += ways(idx+1,i-1,j,'U');
		if(steps[idx]=='D' && canGo(i+1,j)) ct += ways(idx+1,i+1,j,'D');
		if(steps[idx]=='R' && canGo(i,j+1)) ct += ways(idx+1,i,j+1,'R');
		if(steps[idx]=='L' && canGo(i,j-1)) ct += ways(idx+1,i,j-1,'L');
	}

	else{
		if(canGo(i-1,j)) ct += ways(idx+1,i-1,j,'U');
		if(canGo(i+1,j)) ct += ways(idx+1,i+1,j,'D');
		if(canGo(i,j+1)) ct += ways(idx+1,i,j+1,'R');
		if(canGo(i,j-1)) ct += ways(idx+1,i,j-1,'L');
	}

	vis[i][j]=false;
	return ct;
}

int main()
{
	FASTIO
	cin >> steps;
	cout << ways(0,0,0,'?');
}