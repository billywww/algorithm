// recursion
#include<iostream>

int map[][4] = {
  {0,30,6,4},
  {30,0,5,10},
  {6,5,0,20},
  {4,10,20,0}
};

int cur[4] = {0};

void output(){

}
bool check(int n){

}

void backtrace(int n){
  if(n >= 4)
    output();
  for(int i = 0;i < 4;i++){
    cur[n] = i;
    if(map[n][i] > 0&&check(n))
      backtrace(n+1);
  }
}

int main(){

}
