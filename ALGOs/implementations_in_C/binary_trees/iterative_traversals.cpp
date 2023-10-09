#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

vector<int> preOrder(node *curr) // curr-left-right
{
    vector<int> ans;
    if (curr == NULL)
        return ans;

    stack<node *> st;
    st.push(curr);

    while (!st.empty())
    {
        curr = st.top();
        ans.push_back(curr->data);
        st.pop();

        if (curr->right != NULL)
            st.push(curr->right);
        if (curr->left != NULL)
            st.push(curr->left);
    }

    return ans;
}

vector<int> inOrder(node *curr) // left-curr-right
{
    vector<int> ans;
    stack<node *> st;

    while (true)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
                break;

            curr = st.top();
            ans.push_back(curr->data);
            st.pop();
            curr = curr->right;
        }
    }

    return ans;
}

vector<int> postOrderUsing2Stacks(node *curr) // left-right-curr
{
    vector<int> ans;
    if (curr == NULL)
        return ans;

    stack<node *> s1;
    stack<node *> s2;

    s1.push(curr);

    while (!s1.empty())
    {
        curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left != NULL)
            s1.push(curr->left);

        if (curr->right != NULL)
            s1.push(curr->right);
    }

    while (!s2.empty())
    {
        ans.push_back(s2.top()->data);
        s2.pop();
    }

    return ans;
}

vector<int> postOrderUsing1Stack(node *curr) // left-right-curr
{
    vector<int> ans;
    stack<node *> st;

    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);

                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
                curr = temp;
        }
    }

    return ans;
}

vector<vector<int>> levelOrder(node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        vector<int> level;
        int sz = q.size();
        while (sz--)
        {
            node *curr = q.front();
            q.pop();
            level.push_back(curr->data);
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        ans.push_back(level);
    }

    return ans;
}

vector<int> boundaryTraversal(node *root) // Anti-Clockwise
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    // Left Boundary (excluding leaves)
    node *curr = root->left;
    while (curr)
    {
        if (curr->left != NULL || curr->right != NULL)
            ans.push_back(curr->data);

        if (curr->left != NULL)
            curr = curr->left;
        else
            curr = curr->right;
    }

    // Leaves
    curr = root;
    stack<node *> st;
    while (true)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
                break;

            curr = st.top();
            if (curr->left == NULL && curr->right == NULL)
                ans.push_back(curr->data);
            st.pop();
            curr = curr->right;
        }
    }

    // Right Boundary (excluding Leaves)
    curr = root->right;

    while (curr)
    {
        if (curr->left != NULL || curr->right != NULL)
            st.push(curr);

        if (curr->right != NULL)
            curr = curr->right;
        else
            curr = curr->left;
    }

    while (!st.empty())
    {
        ans.push_back(st.top()->data);
        st.pop();
    }

    return ans;
}

vector<vector<int>> verticalOrder(node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    node *curr = root;
    map<int, map<int, multiset<int>>> m;
    queue<pair<node *, pair<int, int>>> q;
    q.push({curr, {0, 0}});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        curr = p.first;
        int vertical = p.second.first, level = p.second.second;
        m[vertical][level].insert(curr->data);

        if (curr->left)
            q.push({curr->left, {vertical - 1, level + 1}});
        if (curr->right)
            q.push({curr->right, {vertical + 1, level + 1}});
    }

    for (auto y : m)
    {
        vector<int> v;
        for (auto x : y.second)
        {
            for (auto val : x.second)
            {
                v.push_back(val);
            }
        }
        ans.push_back(v);
    }

    return ans;
}