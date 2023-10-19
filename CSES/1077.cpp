#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

void balanceHeaps(multiset<int> &maxheap, multiset<int> &minheap, ll &maxsum, ll &minsum)
{
    while (maxheap.size() > minheap.size())
    {
        int tmp = *(maxheap.begin());
        maxheap.erase(maxheap.begin());
        maxsum -= tmp;
        minheap.insert(-tmp);
        minsum += tmp;
    }

    while (minheap.size() - maxheap.size() > 1)
    {
        int tmp = -(*(minheap.begin()));
        minheap.erase(minheap.begin());
        minsum -= tmp;
        maxheap.insert(tmp);
        maxsum += tmp;
    }
}

void printHeap(multiset<int> &heap)
{
    for (auto it : heap)
        cout << it << " ";

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    multiset<int> maxheap; // right half
    multiset<int> minheap; // left half (including median)
    ll minsum = 0, maxsum = 0;

    for (int i = 0; i < k - 1; i++)
    {
        minheap.insert(-x[i]);
        minsum += x[i];
    }

    for (int i = k - 1; i < n; i++)
    {
        if (minheap.empty() && (x[i] < *(maxheap.begin())) || x[i] <= abs(*(minheap.begin())))
        {
            minheap.insert(-x[i]);
            minsum += x[i];
        }
        else
        {
            maxheap.insert(x[i]);
            maxsum += x[i];
        }
        balanceHeaps(maxheap, minheap, maxsum, minsum);

        // printHeap(minheap);
        // printHeap(maxheap);
        
        ll med = -(*(minheap.begin()));
        ll cost = minheap.size() * med - minsum + maxsum - maxheap.size() * med;
        cout << cost << " ";
        auto it = minheap.find(-x[i - k + 1]);
        if (it != minheap.end())
        {
            minheap.erase(it);
            minsum -= x[i - k + 1];
            continue;
        }

        it = maxheap.find(x[i - k + 1]);
        maxheap.erase(it);
        maxsum -= x[i - k + 1];
    }
}