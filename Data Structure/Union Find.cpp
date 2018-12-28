#include<string.h>
class UF{
public:
  UF(int n){
    p = new int[n];
    for(int i=0;i<n;i++){p[i]=-1;}
    rank = new int[n];
    memset(rank,0,n);
  };

  int union_A (int ,int );
  int find(int );

private:
  int *p;
  int *rank;
};

int UF::union_A(int a,int b){
  if(find(a)==find(b)){
    return 0;
  }
  else{
    int m = find(a);
    int n = find(b);
    if(rank[m]>rank[n]){
      p[n]=m;
    }
    else {p[m]=n;}
    if(rank[m]==rank[n]){rank[n]++;}
  }
  return 1;
}

int UF::find(int a){
  if(p[a]==a){
    return a;
  }
  else{
    p[a]=find(a);
    return p[a];
  }
}
