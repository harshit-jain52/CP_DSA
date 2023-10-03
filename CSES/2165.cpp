#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

vector<pair<int, int>> steps;
void towerOfHanoi(int n, int from, int to, int temp)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, from, temp, to); // Move the top (n-1) disks from left to center
    steps.push_back({from, to});         // Move the largest disk from left to right
    towerOfHanoi(n - 1, temp, to, from); // Move the (n-1) disks from center to right
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    towerOfHanoi(n, 1, 3, 2);

    cout << steps.size() << endl;
    for (auto it : steps)
        cout << it.first << " " << it.second << endl;
}