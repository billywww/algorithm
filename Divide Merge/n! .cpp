#include"Bigint.cpp"
/*slow!!!*/
// int factorial(int n){
//   if (n==1){
//     return 1;
//   }
//   else
//   return n*factorial(n-1);
// }

#include<iostream>
Bigint refac(Bigint l,Bigint r){
  if(l==r){
    return l;
  }

  Bigint temp = l+r;
  Bigint mid = temp/Bigint(2);

  return refac(l,mid)*refac(mid+Bigint(1),r);

}

Bigint factorial(int n){
  return refac(Bigint(1),Bigint(n));
}

int main(){
  std::cout<<factorial(2000);
}
