/*
multiple
*/

#include<iostream>


int divide(int a){
  static int k = 0;
  if(a == 1){
    k++;
  }
  for(int i = a; i >= 2 ;i--){
    if(a % i == 0){
      divide(a/i);
    }
  }
    return k;
}

int main(){
  std::cout<<divide(12);
}
