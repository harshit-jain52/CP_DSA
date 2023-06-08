#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i;
    string s = "";

    ifstream infile;
    infile.open("input.txt");
    infile >> n >> m;

    if (n >= m)
    {
        for (i = 0; i < m; i++)
        {
            s.push_back('B');
            s.push_back('G');
        }
        for (; i < n; i++)
        {
            s.push_back('B');
        }
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            s.push_back('G');
            s.push_back('B');
        }
        for (; i < m; i++)
        {
            s.push_back('G');
        }
    }

    ofstream outfile;
    outfile.open("output.txt");
    outfile << s;
}