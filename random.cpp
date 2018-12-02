#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
#define MAX_RANDOM 1000    //这个是产生随机数的最大值，但是取浮点数，所以要除去的

#define NUM 2500

double random(double a,double b)         //这个是产生随机数函数，由于库函数功能有限，所以要自己封装一下
{
 return (rand()%(int)((b-a)*MAX_RANDOM))/(double)MAX_RANDOM+a;
}

int main()
{
 double Dran[NUM + (NUM-1)*4];
 double ran[(NUM-1)*4];
 double a,b;
 int k=0;
 
 srand( (unsigned)time( NULL ) );//这个是设定随机数的种子数，由于种子数相同产生的随机数相同，所以取时间做种子

 //cout<<"***********************************亲体**************************"<<endl;
 for(int i =0;i<NUM + (NUM-1)*4;i=i+5)          //获得了亲体
 {
  Dran[i] = random(10,20);
  cout<<Dran[i]<<" ";
 }
/*
 cout<<"***********************************后代**************************"<<endl;
 //Dran里面是装的亲代和后代一起的，ran里面只是装的后代
 for(i=0;i<NUM + (NUM-1)*4 - 1 ; i=i+5 )
 {
  a = Dran[i];
  b = Dran[i+5];
  for(int j=1;j<=4;j++)
  {
   Dran[i+j] = random(a,b);
   ran[k] = Dran[i+j];
   cout<<ran[k]<<" ";
   k++;
  }
 }
*/
}