/**/

#include<iostream>
#include"multi-head.cpp"
using namespace std;


int main(){
  Task_que tasklist;
  Mach_que machlist(3);

  for(int i = 0;i<10;i++){
    task temp(i+1,(i+4)%10+1);
    tasklist.push_task(temp);
  }

  while(!tasklist.is_empty() || machlist.hasbusy()){
    machlist.flu();

    if(machlist.hasfree()&&!tasklist.is_empty()){
      task temp;
      tasklist.get_task(temp);
      machlist.assign(temp);
    }

  }
}
