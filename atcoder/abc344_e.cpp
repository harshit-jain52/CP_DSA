#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FASTIO                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
typedef long long ll;
const int M = 1e9 + 7;

class ListNode
{
public:
	ListNode *next;
	ListNode *prev;
	int data;
	ListNode(int num = 0, ListNode *n = NULL, ListNode *p = NULL) : data(num), next(n), prev(p) {}
};
int main()
{
	FASTIO
	int n;
	cin >> n;
	int a[n];

	map<int, ListNode *> mp;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]] = new ListNode(a[i]);
	}

	for (int i = 0; i < n - 1; i++)
		mp[a[i]]->next = mp[a[i + 1]];
	for (int i = 1; i < n; i++)
		mp[a[i]]->prev = mp[a[i - 1]];

	ListNode *head = mp[a[0]];

	int q;
	cin >> q;
	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int x, y;
			cin >> x >> y;
			ListNode *front = mp[x]->next;
			mp[y] = new ListNode(y, front, mp[x]);
			if (front)
				front->prev = mp[y];
			mp[x]->next = mp[y];
		}
		else
		{
			int x;
			cin >> x;
			ListNode *back = mp[x]->prev;
			ListNode *front = mp[x]->next;
			if (back)
				back->next = front;
			else
				head = front;

			if (front)
				front->prev = back;

			delete mp[x];
			mp[x] = NULL;
		}
	}

	ListNode *cur = head;
	while (cur)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
}