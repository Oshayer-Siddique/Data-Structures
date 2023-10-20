#include<iostream>
#include<vector>
using namespace std;

struct friendGroup{
    vector<int> members;
    int groupID;
};
struct member{
    int value;
    int ID;
};

int main(){
    int t, Scene=0;
    while(true){
        int n;
        string input;
        vector<friendGroup> Groups;
        vector<member> EQ;
        Scene++;
        cin >> t;
        if(t==0) break;
        cout<<"Scenario #"<<Scene<<endl;
        while(t--){
            cin >> n;
            friendGroup group = {.groupID = t};
            while(n--){
                int m;
                cin >> m;
                group.members.push_back(m);
            }
            Groups.push_back(group);
        }
        while(true){
            cin >> input;
            if(input=="ENQUEUE"){
                int m, ID;
                bool found = false;
                cin >> m;
                for(int i=0;i<Groups.size();i++){
                    for(int j=0;j<Groups[i].members.size();j++){
                        if(m==Groups[i].members[j]){
                            ID = Groups[i].groupID;
                            Groups[i].members.erase(Groups[i].members.begin() + j);
                            found = true;
                            break;
                        }
                    }
                    if(found) break;
                }
                member Friend = {.value = m, .ID = ID};
                found = false;
                for(int i = EQ.size() - 1;i>=0;i--){
                    if(EQ[i].ID == Friend.ID){
                        found = true;
                        EQ.insert(EQ.begin() + i+1, Friend);
                        break;
                    }
                }
                if(!found) EQ.push_back(Friend);
            }
            else if(input=="DEQUEUE"){
                cout<<(*EQ.begin()).value<<endl;
                EQ.erase(EQ.begin());
            }
            else{
                cout<<endl;
                break;
            }
        }
    }
    return 0;
}
