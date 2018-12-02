#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    return a.first<b.first;
}
int main()
{
    int n;cin>>n;
    vector<pair<int,int> > jobs(n);
    vector<vector<pair<int,int> > > machines;
    for(int i=0;i<n;i++)
        cin>>jobs[i].first>>jobs[i].second;
    sort(jobs.begin(),jobs.end(),cmp);
    for(unsigned i=0;i<jobs.size();i++){
        unsigned j;
        for(j=0;j<machines.size();j++){
            if(machines[j].size()==0||machines[j].back().second<=jobs[i].first){
                machines[j].push_back(jobs[i]);
                break;
            }
        }
        if(j==machines.size()){
            vector<pair<int,int> > newmachine(1,jobs[i]);
            machines.push_back(newmachine);
        }
    }
    for(unsigned i=0;i<machines.size();i++){
        cout<<"machine "<<i<<": "<<endl;
        for(unsigned j=0;j<machines[i].size();j++)
            cout<<'('<<machines[i][j].first<<','<<machines[i][j].second<<") ";
        cout<<endl;
    }
    return 0;
}