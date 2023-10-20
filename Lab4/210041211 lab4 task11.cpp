#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void printdeque(deque<char> q)

{

    for (int i = 0; i < q.size(); i++)
    {
        cout << q[i];
    }
}

int main()
{
    deque<char> str;
    string s1, s2;

    cin >> s1;
    cin >> s2;
    for (int i = 0; i < s1.size(); i++)
    {
        str.push_back(s1[i]);
    }
    int flag = 0;
    for (int i = 0; i < 5; i++)
    {
        char ch = str.back();
        str.pop_back();
        str.push_front(ch);

        string data = "";

        for (int i = 0; i < str.size(); i++)
        {
            // cout<<str[i];

            data += str[i];
        }
        if (data == s2)
        {

            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }

        // cout << endl;
    }

    if (flag == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}