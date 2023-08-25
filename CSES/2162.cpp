#include <bits/stdc++.h>
using namespace std;

int rem;

typedef struct LIST
{
    struct LIST *next;
    int data;
} node;

node *createNode(int num)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = num;
    temp->next = NULL;
    return temp;
}

void solve(node *prev, node *curr)
{
    if (rem == 0)
        return;

    prev = curr;
    curr = curr->next;

    cout << curr->data << " ";
    prev->next = curr->next;
    rem--;

    solve(prev, curr->next);
}

int main()
{
    int n;
    cin >> n;

    node *head(createNode(1));
    node *prev = head;
    for (int i = 2; i <= n; i++)
    {
        prev->next = createNode(i);
        prev = prev->next;
    }
    prev->next = head;

    rem = n;
    solve(prev, head);
}