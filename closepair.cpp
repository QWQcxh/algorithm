#include <iostream>
#include <list>
#include <cmath>
using namespace std;
typedef list<pair<double,double>> lp;
typedef pair<double,double> dp;
bool cmpx(const pair<double,double>&p,const pair<double,double>&q){
    return p.first<q.first;
}
bool cmpy(const pair<double,double>&p,const pair<double,double>&q){
    return p.second<q.second;
}
inline double dist(dp p1,dp p2){
    double dx=p1.first-p2.first;
    double dy=p1.second-p2.second;
    return dx*dx+dy*dy;//don't use sqrt to reduce calculsation
}
pair<dp,dp> closest_pair(lp& px,lp& py){
    pair<dp,dp> res;
    if(px.size()==2){res.first=px.front();res.second=px.back();return res;}
    if(px.size()==3){
        lp::iterator it=px.begin();++it;//it points to the second point
        double d1,d2,d3;//d1 with distance of p1,p2 .d2 with dis p2 p3
        d1=dist(px.front(),*it);
        d2=dist(*it,px.back());
        d3=dist(px.front(),px.back());
        if(d1<=d2&&d1<=d3) {res.first=px.front();res.second=*it;}
        else if(d2<=d1&&d2<=d3) {res.first=*it;res.second=px.back();}
        else {res.first=px.front();res.second=px.back();}
        return res;
    } //base case
    lp Qx,Qy,Rx,Ry;
    int mid_pnt=px.size()/2;
    double L;
    int count=0;lp::iterator it;
    for(it=px.begin();count<mid_pnt;count++,it++) Qx.push_back(*it);
    L=it->first;//L is x-coordinate of mid point px
    for(;it!=px.end();++it) Rx.push_back(*it);
    for(it=py.begin();it!=py.end();++it)
        if(it->first<L) Qy.push_back(*it);
        else Ry.push_back(*it);//get qx,qy,rx,ry
    px.clear();
    pair<dp,dp> point_pair1=closest_pair(Qx,Qy);
    pair<dp,dp> point_pair2=closest_pair(Rx,Ry);
    Qx.clear();Qy.clear();Rx.clear();Ry.clear();
    double d1=dist(point_pair1.first,point_pair1.second);
    double d2=dist(point_pair2.first,point_pair2.second);
    double d=min(d1,d2);
    if(d1<d2) res=point_pair1;
    else res=point_pair2;
    double bindl=L-d,bindr=L+d;
    for(it=py.begin();it!=py.end();it++)
        if(it->first<=bindl||it->first>=bindr) {py.erase(it);it--;} //get list in band
    lp::iterator it2;
    for(it=py.begin();it!=py.end();it++){
        it2=it;
        for(++it2,count=0;it2!=py.end()&&count<16;it2++,count++)
            if(dist(*it,*it2)<d){d=dist(*it,*it2);res.first=*it;res.second=*it2;}
    }
    py.clear();
    return res;
}
int main()
{
    int n;
    lp P,Px,Py;
    pair<double,double> point;
    while(cin>>n&&n){
        P.resize(0);
        while(n--){
            cin>>point.first>>point.second;
            P.push_back(point);
        }
        Py=Px=P;
        Px.sort(cmpx);
        Py.sort(cmpy);
        pair<dp,dp> res=closest_pair(Px,Py);
        cout<<"the closest points pair is: "<<endl;
        cout<<'('<<res.first.first<<","<<res.first.second<<')'<<' '
        <<'('<<res.second.first<<','<<res.second.second<<')'<<endl;
        cout<<"and the distance is:\n";
        printf("%f\n",sqrt(dist(res.first,res.second)));
    }
    return 0;
}