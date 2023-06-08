#include <bits/stdc++.h>

using namespace std;

int main()
{
    string dubstep, song = "", songlefttrimmed = "";
    int i, flag = 0;
    cin >> dubstep;
    dubstep += "  ";

    for (i = 0; i < dubstep.size() - 2;)
    {
        if (dubstep[i] == 'W' && dubstep[i + 1] == 'U' && dubstep[i + 2] == 'B')
        {
            flag = 1;
            i += 3;
        }
        else
        {
            if (flag == 1)
            {
                song.push_back(' ');
            }
            song.push_back(dubstep[i]);
            i++;
            flag = 0;
        }
    }

    //removing leading spaces
    for (i = 0; i < song.size(); i++)
    {
        if (song[i] != ' ')
        {
            break;
        }
    }

    for (; i < song.size(); i++)
    {
        songlefttrimmed.push_back(song[i]);
    }

    cout << songlefttrimmed;
}