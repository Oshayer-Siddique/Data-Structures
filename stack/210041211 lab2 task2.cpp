#include <iostream>
#include <stack>
#include <windows.h>
#include <string>
#define M = 10000000007
#define ll long long
#define ull long long

using namespace std;

int main()
{
    int n, len, o;
    bool check = true;
    stack<string> st;
    int checker;
    string value, value2;
    cin >> n;
    for (int p = 0; p <= n + 1; p++)
    {
        string str;
        getline(cin, str);
        len = str.length();
        for (size_t i = 0; i < len; i++)
        {
            if (str[i - 1] == '<' && str[i] != '/')
            {
                o = 0;
                for (size_t j = i;; j++)
                {
                    if (str[j] == '>')
                    {

                        break;
                    }
                    else

                    {
                        value += str[j];
                        // cout<<o<<" ";
                    }
                }

                st.push(value);
                value.clear();
            }

            if (str[i - 1] == '<' && str[i] == '/')
            {
                o = 0;
                for (size_t j = i + 1;; j++)
                {
                    if (str[j] == '>')
                    {

                        break;
                    }
                    else
                    {
                        value2 += str[j];
                    }
                }

                //  cout<<value2<<" "<<st.top()<<" ";
                if (value2 == st.top())
                {
                    st.pop();
                }
                else
                {
                    check = false;
                    checker = p;
                    st.pop();
                    break;
                }
                value2.clear();
            }

            if (str == "-1" || check == false)
            {
                break;
            }
        }
    }
    if (check == false || !st.empty())
    {

        cout << "error at line " << checker << endl;

        exit(0);
    }

    if (st.empty())
    {

        cout << value << endl
             << value2 << endl;

        cout << "no error" << endl;
    }
    return 0;
}
