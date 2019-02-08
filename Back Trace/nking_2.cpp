#include<iostream>
#define set(n) lim=(1<<n)-1;

int lim,n= 0;

void nqueen(int d,int ld,int rd){
  if(d!=lim){
    int gb = (~(d|ld|rd))&lim;
    while(gb!=0){
      int pb = gb&(-gb);
      gb -= pb;
      nqueen(d+pb,(ld+pb)<<1,(rd+pb)>>1);
    }
  }
  else n++;
}

int main(){
  set(15);
  nqueen(0,0,0);
  std::cout<<n;
}
