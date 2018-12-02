#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct hos{
    priority_queue<int> hosq;
    unsigned int cap;
    vector<int> map,pre_list;
};
int main() 
{
    int s_num,h_num,i,j,k;cin>>s_num>>h_num;
    vector<vector<int> > stu(s_num);
    vector<int> ind(s_num);
    queue<int> s_que;
    for(i=0;i<s_num;i++) stu[i].resize(h_num);
    for(i=0;i<s_num;i++){
        for(j=0;j<h_num;j++)
            cin>>stu[i][j];
        s_que.push(i);
        ind[i]=0;
    }//initial studen
    vector<hos> h(h_num);
    for(i=0;i<h_num;i++){
        cin>>h[i].cap;
        h[i].map.resize(s_num);
        h[i].pre_list.resize(s_num);
        for(j=0;j<s_num;j++){
            cin>>k;h[i].map[k]=j;h[i].pre_list[j]=k;
        }
    }//initial hospital
    while(!s_que.empty()){
        int s_id=s_que.front();
        int cu_hos=stu[s_id][ind[s_id]];
        if(cu_hos==h_num)
            s_que.pop();
        else{
            if(h[cu_hos].hosq.size()<h[cu_hos].cap){
                h[cu_hos].hosq.push(h[cu_hos].map[s_id]);
                s_que.pop();
            }
            else if(h[cu_hos].hosq.top()>h[cu_hos].map[s_id]){
                s_que.push(h[cu_hos].pre_list[h[cu_hos].hosq.top()]);
                h[cu_hos].hosq.pop();
                h[cu_hos].hosq.push(h[cu_hos].map[s_id]);
                s_que.pop();
            }
            else ind[s_id]++;
        }
    }
    for(i=0;i<h_num;i++){
        while(!h[i].hosq.empty()){
            cout<<'('<<i<<','<<h[i].pre_list[h[i].hosq.top()]<<')'<<' ';
            h[i].hosq.pop();
        }
        cout<<endl;
    }
}