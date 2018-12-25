/*way of memo*/

#include<iostream>
using namespace std;

int m[100][100]={0};
int p[12]={30,35,35,15,15,5,5,10,10,20,20,25};

int chain(int i,int j){
  if(m[i][j] > 0){return m[i][j];}
  if(i == j){return 0;}
  m[i][j] = chain(i,i)+chain(i+1,j)+p[2*i]*p[2*i+1]*p[2*j+1];
  for(int k = i; k <j; k++){
    int u = chain(i,k)+chain(k+1,j)+p[2*i]*p[2*k+1]*p[2*j+1];
    if(u <= m[i][j]){
      m[i][j] = u;
    }
  }
  return m[i][j];
}

int main() {
  cout << chain(0,5);
  return 0;
}
