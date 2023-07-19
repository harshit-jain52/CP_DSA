#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    deque<string> q;
    while (n--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "cd")
        {
            string directory;
            cin >> directory;
            directory.push_back('/');
            int i = 0;
            if (directory[0] == '/')
            {
                q.clear();
                i = 1;
            }
            string tmpstr = "";
            for (; i < directory.size(); i++)
            {
                if (directory[i] != '/')
                {
                    tmpstr.push_back(directory[i]);
                }
                else
                {
                    if (tmpstr == "..")
                        q.pop_back();
                    else
                        q.push_back(tmpstr);

                    tmpstr = "";
                }
            }
        }
        else
        {
            deque tmp = q;
            cout << '/';
            while (!tmp.empty())
            {
                cout << tmp.front();
                cout << '/';
                tmp.pop_front();
            }
            cout << endl;
        }
    }
}