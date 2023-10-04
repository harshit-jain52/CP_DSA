#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i;
    cin >> n >> m;
    int a[n + 1], idx[n + 1];

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        idx[a[i]] = i;
    }

    int ct = 1;

    for (i = 2; i <= n; i++)
    {
        if (idx[i] < idx[i - 1])
        {
            ct++;
        }
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        
        if(x==y)
        {
            cout << ct<<endl;
            continue;
        }

        if (x > y)
            swap(x, y);

        int num1 = a[x], num2 = a[y];

        int oldpos1 = x, newpos1 = y;
        int oldpos2 = y, newpos2 = x;

        if(abs(num1-num2)==1)
        {
            if(num1>num2){
                ct--;

                if(num1<n && idx[num1+1]>oldpos1 && idx[num1+1]<newpos1) ct++;
                if(num1<n && idx[num1+1]<oldpos1 && idx[num1+1]>newpos1) ct--;


                if(num2>1 && idx[num2-1]<oldpos2 && idx[num2-1]>newpos2) ct++;
                if(num2>1 && idx[num2-1]>oldpos2 && idx[num2-1]<newpos2) ct--;
            }
            else
            {
                ct++;

                if(num1>1 && idx[num1-1]<oldpos1 && idx[num1-1]>newpos1) ct++;
                if(num1>1 && idx[num1-1]>oldpos1 && idx[num1-1]<newpos1) ct--;

                if(num2<n && idx[num2+1]>oldpos2 && idx[num2+1]<newpos2) ct++;
                if(num2<n && idx[num2+1]<oldpos2 && idx[num2+1]>newpos2) ct--;
            }
        }
        else
        {
            if(num1>1 && idx[num1-1]<oldpos1 && idx[num1-1]>newpos1) ct++;
            if(num1>1 && idx[num1-1]>oldpos1 && idx[num1-1]<newpos1) ct--;
            if(num1<n && idx[num1+1]>oldpos1 && idx[num1+1]<newpos1) ct++;
            if(num1<n && idx[num1+1]<oldpos1 && idx[num1+1]>newpos1) ct--;


            if(num2>1 && idx[num2-1]<oldpos2 && idx[num2-1]>newpos2) ct++;
            if(num2>1 && idx[num2-1]>oldpos2 && idx[num2-1]<newpos2) ct--;
            if(num2<n && idx[num2+1]>oldpos2 && idx[num2+1]<newpos2) ct++;
            if(num2<n && idx[num2+1]<oldpos2 && idx[num2+1]>newpos2) ct--;
        }

        a[oldpos1] = num2;
        a[oldpos2] = num1;
        idx[num1] = newpos1;
        idx[num2] = newpos2;

        cout << ct << endl;
    }
}