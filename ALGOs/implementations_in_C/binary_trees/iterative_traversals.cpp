#include <bits/stdc++.h>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

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