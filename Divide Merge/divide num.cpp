//将整数划分多个数之和

#include<iostream>
using namespace std;

int divide(int n, int m){
  if(m == 0 || n == 0){return 0;}
  if(n == m) {return 1 + divide(n,m-1);}
  if(m == 1 || n == 1){return 1;}
  if(m > n){return divide(n,n);}
  else {return divide(n - m,m) + divide(n, m - 1);}
}

int main(){
  int a,b;
  cin >> a >>b;
  cout << divide(a,b);
}
