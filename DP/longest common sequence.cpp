/*
最长公共子序列
2018/10/16
*/

#include<iostream>
#include<string.h>
using namespace std;

char stack[1000];
int sp=0;

int common(char* a ,int m, char* b, int n){
  int temp[m+1][n+1];
  int maxn = 0;
  for(int i = 0 ; i <= m ; i++){temp[i][0] = 0;}
  for(int i = 0 ; i <= n ; i++){temp[0][i] = 0;}
  for(int i = 1 ; i <= m ; i++){
    for(int j = 1 ; j <= n ; j++){
      if(a[i-1] == b[j-1]){
        temp[i][j] = temp[i-1][j-1] + 1;

      }
      else{
        temp[i][j] = max(temp[i-1][j] , temp[i][j-1]);
      }
      if(temp[i][j] > maxn){maxn = temp[i][j];stack[sp++] = a[i-1];}  // mark the data
    }
  }
  return maxn;
}

int main(void){
  char *a = new char[1000];
  char *b = new char[1000];
  cout << "input str1 :" << endl;
  cin >> a ;
  cout << "input str2 :" << endl;
  cin >> b ;

  int re = common(a,strlen(a),b,strlen(b));
  cout << re<<endl;
  
  for(int i = 0;i < sp;i++)
  cout<<stack[i];
}
