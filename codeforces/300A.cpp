#include <bits/stdc++.h>
using namespace std;

void printSets(vector<int> &v)
{
    cout << v.size() << " ";
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    int n, temp, i;
    vector<int> set1, set2, set3;
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp < 0)
        {
            set1.push_back(temp);
        }
        else if (temp > 0)
        {
            set2.push_back(temp);
        }
        else
        {
            set3.push_back(temp);
        }
    }

    if (set2.size() == 0)
    {
        set2.push_back(set1[set1.size() - 1]);
        set1.pop_back();
        set2.push_back(set1[set1.size() - 1]);
        set1.pop_back();
    }

    if (set1.size() % 2 == 0)
    {
        set3.push_back(set1[set1.size() - 1]);
        set1.pop_back();
    }

    printSets(set1);
    printSets(set2);
    printSets(set3);
}