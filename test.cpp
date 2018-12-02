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
double closest_pair(lp px,lp py){
    if(px.size()==2){return dist(px.front(),px.back());}
    if(px.size()==3){
        lp::iterator it=px.begin();++it;//it points to the second point
        double d1,d2,d3;//d1 with distance of p1,p2 .d2 with dis p2 p3
        d1=dist(px.front(),*it);
        d2=dist(*it,px.back());
        d3=dist(px.front(),px.back());
        return min(min(d1,d2),d3);
    } //base case
    lp Qx,Qy,Rx,Ry;
    int mid_pnt=px.size()/2,L;
    int count=0;lp::iterator it;
    for(it=px.begin();count<=mid_pnt;count++,it++) Qx.push_back(*it);
    L=it->first;//L is x-coordinate of mid point px
    for(;it!=px.end();++it) Rx.push_back(*it);
    for(it=py.begin();it!=py.end();++it)
        if(it->first<L) Qy.push_back(*it);
        else Ry.push_back(*it);//get qx,qy,rx,ry
    px.clear();
    double d1=closest_pair(Qx,Qy);
    double d2=closest_pair(Rx,Ry);
    Qx.clear();Qy.clear();Rx.clear();Ry.clear();
    double d=min(d1,d2);
    double bindl=L-d,bindr=L+d;
    for(it=py.begin();it!=py.end();it++)
        if(it->first<=bindl||it->first>=bindr) {py.erase(it);it--;} //get list in band
    lp::iterator it2;
    for(it=py.begin();it!=py.end();it++){
        it2=it;
        for(++it2,count=0;it2!=py.end()&&count<16;it2++,count++)
            if(dist(*it,*it2)<d){d=dist(*it,*it2);}
    }
    py.clear();
    return d;
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
        cout<<"and the distance is:\n";
        printf("%.2f\n",sqrt(closest_pair(Px,Py))/2);
    }
    return 0;
}