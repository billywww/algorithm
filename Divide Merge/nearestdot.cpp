/*二维坐标最近点*/

#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

struct point{
  int x;
  int y;
};

int distance(point a,point b){
  int dx = a.x - b.x;
  int dy = a.y - b.y;
  return sqrt(dx*dx + dy*dy);
}

int closest(point *arr,int p,int t,int r,int d){
  int min = 1000;
  for(int i = p;i <= t; i++){
    int k = t+1;
    while(arr[k].x <= d){
      int l = distance(arr[i],arr[k]);
      if(l < min){
        min = l;
      }
      k++;
    }
  }
  return min;
}

int cpairl(point *arr,int p,int r){
  if(r-p == 0){
    return 1000;
  }
  else{
    int i = (p + r) / 2;
    int m = cpairl(arr,p,i);
    int n = cpairl(arr,i+1,r);
    int d = min(m,n);
    int s = closest(arr,p,i,r,d);
    return min(d,s);
  }
}

int main(){
  point arr[6]={{1,1},{4,1},{4,4},{6,1},{9,1},{9,5}};
  cout << cpairl(arr,0,5);
  return 0;
}
