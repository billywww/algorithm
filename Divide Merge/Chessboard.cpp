/*
2018/10/27
*/

#include<iostream>
using namespace std;

int arr[8][8] = {0};


int check(int a,int m,int n){
  int flag=0;
  for(int i = m;i < m+a;i++){
    for(int j = n;j < n+a;j++){
      if(arr[i][j] != 0){
        flag = 1;
        break;
      }
    }
  }
  return flag;
}

int chessboard(int k,int x,int y){

  if(k==1){
    return 1;
  }
  else{
    if(check(k/2,x,y)){
       chessboard(k/2,x,y);
    }
    else{
      arr[x+k/2-1][y+k/2-1]=k;
       chessboard(k/2,x,y);
    }

    if(check(k/2,x,y+k/2)){
      chessboard(k/2,x,y+k/2);
    }
    else{
      arr[x+k/2-1][y+k/2]=k;
      chessboard(k/2,x,y+k/2);
    }

    if(check(k/2,x+k/2,y)){
       chessboard(k/2,x+k/2,y);
    }
    else{
      arr[x+k/2][y+k/2-1]=k;
       chessboard(k/2,x+k/2,y);
    }

    if(check(k/2,x+k/2,y+k/2)){
       chessboard(k/2,x+k/2,y+k/2);
    }
    else{
      arr[x+k/2][y+k/2]=k;
     chessboard(k/2,x+k/2,y+k/2);
    }
  }
  return 1;
}

int main(){
  arr[0][1]=1;
  chessboard(8,0,0);
  for(int i = 0;i < 8;i++){
    for(int j = 0;j < 8;j++){
      cout << arr[i][j]<< ' ';
    }
    cout <<endl;
  }
}
