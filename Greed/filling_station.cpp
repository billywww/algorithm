
#include <fstream>
using namespace std;

int filling(int step,int n,int* distance){
  int cur = 0;
  int count = 0;
  int rest = step;
  while(cur < 8){
    if(rest >= distance[cur]){
      rest -= distance[cur];
    }
    else {
      count ++;
      rest = step - distance[cur];
    }
    cur++;
  }
  return count;
}

int main(){
  fstream myfile;
  myfile.open("input.txt");
  int step_in;
  myfile>>step_in;
  int num;
  myfile>>num;
  int distance[num+1];
  for(int i= 0;i<=num;i++){
     myfile>>distance[i];
  }
  myfile.close();

  ofstream myfile2;
  myfile2.open("output.txt");
  myfile2 << filling(step_in,num,distance);
  myfile2.close();
}
