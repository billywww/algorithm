#include<iostream>
using namespace std;

class Board{
public:
  Board(int n):size(n),num(0){
    arr = new int[n]{0};
  }
  bool check(const int& y,const int& x){
    for(int i = 0;i < y; i++){
      if(x == arr[i] || arr[i]-x == y-i
      ||arr[i]-x == i-y)
        return false;
    }
    return true;
  }
  void print(){
    for(int i=0;i<size;i++){
      int j = 0;
      while(j<arr[i]){cout<<'O';j++;}
      cout<<'X';j++;
      while(j<size){cout<<'O';j++;}
      cout<<endl;
    }
    cout<<endl;
  }
  void work(int);
  void count(){
    cout<<num;
  }
private:
  int size;
  int num;
  int *arr;
};

void Board::work(int k){
  if(k>=size) {
  //  print();
    num++;
    return;
  }
  for(int i=0;i<size;i++){
    if(check(k,i)){
        arr[k] = i;
        work(k+1);
    }
  }
}

void nking(int n){
  Board bor(n);
  bor.work(0);
  bor.count();
}

int main(){
  nking(14);
}
