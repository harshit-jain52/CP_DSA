#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

vector<int> topView(node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    node *curr = root;
    map<int, int> m;
    queue<pair<node *, int>> q;
    q.push({curr, 0});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int vertical = p.second;
        curr = p.first;

        if (m.find(vertical) == m.end()) // Remove this check to get Bottom View
            m[vertical] = curr->data;

        if (curr->left)
            q.push({curr->left, vertical - 1});
        if (curr->right)
            q.push({curr->right, vertical + 1});
    }

    for (auto it : m)
    {
        ans.push_back(it.second);
    }

    return ans;
}

vector<int> sideView(node *root) // Right Side
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    node *curr = root;
    map<int, int> m;
    queue<pair<node *, int>> q;
    q.push({curr, 0});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int level = p.second;
        curr = p.first;

        if (m.find(level) == m.end())
            m[level] = curr->data;

        if (curr->right)
            q.push({curr->right, level + 1});
        if (curr->left)
            q.push({curr->left, level + 1});
        // Reverse the order of above 2 statements to get Left View
    }

    for (auto it : m)
    {
        ans.push_back(it.second);
    }

    return ans;
}

void sideViewRecursive(node *root, int level, vector<int> &v) // Right Side
{
    if (root == NULL)
        return;

    if (level == v.size())
        v.push_back(root->data);

    sideViewRecursive(root->right, level + 1, v);
    sideViewRecursive(root->left, level + 1, v);
    // Reverse the order of above 2 statements to get Left View
}