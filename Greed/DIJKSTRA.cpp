#include<iostream>
#define INT_MAX 10000
using namespace std;

int weight[5][5]={
  {INT_MAX,10,INT_MAX,30,100},
  {INT_MAX,INT_MAX,50,INT_MAX,INT_MAX},
  {INT_MAX,INT_MAX,INT_MAX,INT_MAX,10},
  {INT_MAX,INT_MAX,20,INT_MAX,60},
  {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX}
};

void dijkstra(int sou,int n,int prev[]){
  int distance[n];
  bool exist[n] ;
  for(int i = 0;i<n;i++){
    distance[i] = weight[sou][i];
    if(distance[i]<INT_MAX) prev[i] = sou;
      else prev[i] = -1;
  }

  exist[sou] = true;
  for(int i = 1;i< n;i++){
    int temp = INT_MAX;
    int new_node = sou;
    for(int j = 0;j< n;j++){
      if(exist[j] == false&&distance[j]<temp){
        temp = distance[j];
        new_node = j;
      }
}
      exist[new_node]=true;

      for(int j = 0;j< n;j++){
        if(exist[j] == false && weight[new_node][j]+distance[new_node] < distance[j]){
          distance[j] = weight[new_node][j]+distance[new_node];
          prev[j] = new_node;
        }
      }


  }
}

int main(){
  int prev[5]={0};
  dijkstra(0,5,prev);

  for(auto i:prev){
     cout<<i<<' ';
  }

}
