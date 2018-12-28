#include<iostream>

//undirected graph
class UDG{
public:
  UDG(int n,int **e,int m):num(n),count(0),num_color(m){
    edge = e;
    way = new int[n+1];
  }
  bool check(int);
  void backtrace(int);
private:
  int **edge;
  int *way;
  int num_color;
  int num;
  int count;
};

bool UDG::check(int deepth){
  for(int i =1;i<deepth;i++)
    if(edge[deepth][i]&&way[deepth] == way[i])
      return false;
  return true;
}


void UDG::backtrace(int deep){

  if(deep > num ){
    for(int i = 1;i<=num;i++)
      std::cout<<way[i]<<' ';
    std::cout<<std::endl;
    count++;
  }
  else{
    for(int i = 1;i <= num_color; i++){
      way[deep] = i;
      if(check(deep)){backtrace(deep+1);}
      way[deep] = 0;
    }
  }
}


int main(){
  int table[][6] = {
    {0,0,0,0,0,0},
    {0,0,1,1,1,0},
    {0,1,0,1,1,1},
    {0,1,1,0,1,0},
    {0,1,1,1,0,1},
    {0,0,1,0,1,0}
  };
  int *ptr[] = {table[0],table[1],table[2],table[3],table[4],table[5]};
  int **q = ptr;

  UDG map(5,q,4);
  map.backtrace(1);
}
