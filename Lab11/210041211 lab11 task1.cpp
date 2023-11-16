#include <iostream>
#include <vector>

using namespace std;


int linear(vector<int> & h_table,int val,int sz)
{
    int idx = val % sz;
    int attmp = 0;
    while(attmp < 6)
    {
        if(h_table[idx] == -1)
        {
            h_table[idx] = val;
            return idx;

        }
        else
        {
            idx = (val+attmp) % sz;
            attmp++;

        }
    }


    return -1;
}


int quadratic(vector<int> & h_table,int val,int sz)
{

    int attmp = 0;

    int idx = val % sz;

    while(attmp < 6)
    {
        if(h_table[idx] == -1)
        {
            h_table[idx] = val;
            return idx;

        }
        else
        {
            idx = (val+attmp*attmp) % sz;
            attmp++;

        }
    }


    return -1;
}

int double_hashing(vector<int> & h_table,int val,int sz)
{


    int idx = val % sz;
    int h2 = 7 - (val % 7);
    int attmp = 0;
    while(attmp < 6)
    {
        if(h_table[idx] == -1)
        {
            h_table[idx] = val;
            return idx;

        }
        else
        {
            idx = (idx + attmp * h2) % sz;
            attmp++;
        }
    }

    return -1;






}

int main()
{
    int f_id,n,q;
    cin >> f_id >> n >> q;
    vector<int> h_table(n,-1);
    int u = 0;
    int v = 0;
    int w = 0;
    for(int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        int index;

        if(f_id == 1)
        {
            index = linear(h_table,x,n);
            if(index != -1)
            {

                u++;
                cout<<"Inserted : Index -> " <<index<<"  "<<"L:F->"<<(double(u)/10) * 10<<endl;
            }
            else
            {
                cout<<"Not possible"<<endl;
            }
        }
        else if(f_id == 2)
        {
            index = quadratic(h_table,x,n);
            if(index != -1)
            {
                v++;
                cout<<"Inserted : Index -> " <<index<<"  "<<"L:F->"<<(double(v)/n)<<endl;
            }
            else
            {
                cout<<"Not possible"<<endl;
            }
        }

        else if(f_id == 3)
        {

            index = double_hashing(h_table,x,n);
            if(index != -1)
            {
                w++;
                cout<<"Inserted : Index -> " <<index<<"  "<<"L:F->"<<(double(w)/n)<<endl;
            }
            else
            {
                cout<<"Not possible"<<endl;
            }

        }




    }

}
