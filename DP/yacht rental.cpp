/*rent yacht with least cost*/

#include<iostream>
#include<fstream>
using namespace std;

int wcost(int n,int c[][100]){
  int m [100][100];
  for(int i =0;i<=n;i++){
    m[i][i]=0;
  }
  for(int r = 1;r < n; r++){
    for(int i = 1;i <= n-r;i++){
      int j = i+r;
      m[i][j] = c[i][j];
      for(int k = i+1;k<j;k++){
        int t = m[i][k]+m[k][j];
        if(t < m[i][j]){
          m[i][j] = t;
        }
      }
    }
  }
  return m[1][n];
}

int main(){
  int cost[100][100] = {0};
  int n;
  ifstream myFile;
  myFile.open("input.txt");   //input in input.txt
  myFile >> n;
  for(int i = 1;i<n;i++){
    for(int j= i+1;j<=n;j++){
      myFile>>cost[i][j];
    }
  }
  myFile.close();

  int r = wcost(n,cost);
  cout<<"answer has been written in output.txt";
  ofstream myFile2;
  myFile2.open("output.txt");
  myFile2<<r;
  myFile2.close();

}
