#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream infile;
    infile.open("input.txt");

    ofstream outfile;
    outfile.open("output.txt");

    int n, temp, i, flag = 1;
    infile >> n;

    map<int, vector<int>> indices;

    for (i = 0; i < 2 * n; i++)
    {
        infile >> temp;
        indices[temp].push_back(i + 1);
    }

    for (auto it : indices)
    {
        if (it.second.size() % 2 == 1)
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
        for (auto it : indices)
        {
            for (i = 0; i < it.second.size(); i++)
            {
                if (i % 2 == 0)
                {
                    outfile << endl;
                }
                else
                {
                    outfile << " ";
                }
                outfile << it.second[i];
            }
        }
    }
    else
    {
        outfile << -1;
    }
}