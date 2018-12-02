#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
// #define C 1
#define A 2
#define B 2 //weigh of y
using namespace std;
string x,y,bufx,bufy;
int len=1;
typedef vector<vector<int> > Array;
inline int min3(int a,int b,int c){return min(c,min(a,b));}
int C(int i,int j){
    if(x[i-1]==y[j-1]) return 0;
    else return 3;
}
void show(Array& map,int i,int j){
    if(i==0){
        for(int m=1;m<=j;m++,len++){bufx[m]=' ';bufy[m]=y[m-1];}
        return ;
    }
    else if(j==0){
        for(int m=1;m<=i;m++,len++) {bufx[m]=x[m-1];bufy[m]=' ';}
        return;
    }
    if(map[i][j]==C(i,j)+map[i-1][j-1]){
        show(map,i-1,j-1);
        bufx[len]=x[i-1];
        bufy[len]=y[j-1];
    }
    else if(map[i][j]==A+map[i-1][j]){
        show(map,i-1,j);
        bufx[len]=x[i-1];
        bufy[len]=' ';
    }
    else{
        show(map,i,j-1);
        bufx[len]=' ';
        bufy[len]=y[j-1];
    }
    len++;
}
int main()
{
    unsigned int i;
    while(cin>>x&&cin>>y){
        len=1;
        Array map(x.size()+1);
        bufx.resize(x.size()+y.size()+10);
        bufy.resize(x.size()+y.size()+10);
        for(i=0;i<=x.size();i++) map[i].resize(y.size()+1);//build map
        /*initialize begin*/
        for(i=0;i<=y.size();i++) map[0][i]=i*B;
        for(i=0;i<=x.size();i++) 
            map[i][0]=i*A;
        /*initialize end*/ 
        for(i=1;i<=x.size();i++)
            for(unsigned int j=1;j<=y.size();j++)
                map[i][j]=min3(C(i,j)+map[i-1][j-1],A+map[i-1][j],B+map[i][j-1]);
        show(map,x.size(),y.size());
        cout<<"the match is as below:\n";
        for(i=1;i<len;i++) cout<<bufx[i]; 
        cout<<endl;
        for(i=1;i<len;i++) cout<<bufy[i]; 
        cout<<endl;
    }
    return 0;
}