#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

set<string> allPossible;
bool taken[8];

void generate(string &s, string &str)
{
    if (str.size() == s.size())
        allPossible.insert(str);

    for (int i = 0; i < s.size(); i++)
    {
        if (!taken[i])
        {
            taken[i] = true;
            str.push_back(s[i]);
            generate(s, str);
            str.pop_back();
            taken[i] = false;
        }
    }
}

int main()
{
    string s, str = "";
    cin >> s;
    generate(s, str);
    cout << allPossible.size() << endl;
    for (auto it : allPossible)
        cout << it << endl;
}