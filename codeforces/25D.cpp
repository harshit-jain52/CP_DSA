#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int parent[N];
int set_size[N];
set<int> roots;

void make(int v)
{
    parent[v] = v;
    set_size[v] = 1;
}

int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

void merge(int a, int b)
{
    roots.erase(b);
    roots.insert(a);
}

void unionBySize(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (set_size[a] < set_size[b])
            swap(a, b);

        merge(a, b);
        parent[b] = a;
        set_size[a] += set_size[b];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> cycle;

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b))
        {
            cycle.push_back({a, b});
        }
        unionBySize(a, b);
    }

    roots.clear();
    for (int i = 1; i <= n; i++)
    {
        roots.insert(find(i));
    }

    cout << roots.size() - 1 << endl;
    for (auto it : cycle)
    {
        int child = it.first, parent = it.second;

        for (auto r : roots)
        {
            if (find(child) != r)
            {
                cout << child << " " << parent << " " << child << " " << r << endl;
                unionBySize(child, r);
                break;
            }
        }
    }
}