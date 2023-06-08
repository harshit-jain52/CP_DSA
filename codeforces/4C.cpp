#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string name;
    map<string, int> user;
    map<string, int>::iterator it;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        it = user.find(name);
        if (it == user.end())
        {
            user[name] = 0;
            cout << "OK";
        }
        else
        {
            cout << name << ++user[name];
        }
        cout << endl;
    }
}