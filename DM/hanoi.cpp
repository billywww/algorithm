//hanoi塔递归算法

#include<iostream>
using namespace std;

void move(int a,int b){
  cout << "move from " << a << " to " << b <<endl;
}

void hanoi(int n,int a,int b,int c){
  if(n == 0){

  }
  else{
    hanoi(n-1,a,c,b);
    move(a,b);
    hanoi(n-1,c,b,a);
  }
}

int main(){
  int n;
  cin >> n ;
  hanoi(n,1,2,3);
}
