#include <iostream>
using namespace std;

// Forward declarations
class Node;
class List;

class Iterator
{
    Node *node; // Current Node
    List *list; // Current List
public:
    Iterator() : node(nullptr), list(nullptr) {}
    void begin(List *); // Init
    bool end();         // Check end
    void next();        // Go to next
    int data();         // Get node data
};

class List
{
    Node *head, *tail;

public:
    List(Node *h = nullptr) : head(h), tail(h) {} // List Constructor
    void append(Node *p);                         // Add element at the end of LL
    friend class Iterator;
};

class Node
{
    int info;
    Node *next;

public:
    Node(int i) : info(i), next(nullptr) {} // Node Constructor
    friend class List;
    friend class Iterator;
};

// Iterator methods
void Iterator::begin(List *l)
{
    list = l;
    node = l->head; // Set list & Init
}
bool Iterator::end() { return node == nullptr; }
void Iterator::next() { node = node->next; }
int Iterator::data() { return node->info; }

void List::append(Node *p)
{
    if (!head)
        head = tail = p;
    else
    {
        tail->next = p;
        tail = tail->next;
    }
}

/*
int main()
{
    List l;
    Node n1(1), n2(2), n3(3);
    l.append(&n1);
    l.append(&n2);
    l.append(&n3);
    Iterator i;

    // Iteration Loop
    for (i.begin(&l); !i.end(); i.next())
        cout << i.data() << " ";
}
*/