
#include"heap.cpp"
#include<deque>
using namespace std;

class task{
public:
  task()=default;
  task(int i,int t):id(i),time(t){}

  bool operator <=(const task& r) const {
    return time<=r.time?true:false;
  }
  bool operator >=(const task& r) const {
    return time>=r.time?true:false;
  }
  bool operator <(const task& r) const {
    return time<r.time?true:false;
  }
  bool operator >(const task& r) const {
    return time>r.time?true:false;
  }
  bool operator ==(const task& r) const {
    return time==r.time?true:false;
  }

  int id;
  int time;
};


class Task_que{
public:
  void get_task(task& a){
    heap.removeMin(a);
  }
  void push_task(const task& a){
    heap.insert(a);
  }
  bool is_empty(){
    return heap.isEmpty();
  }
private:
  MinHeap<task> heap;
};



class Mach_que{
  typedef struct{
    int id;
    int tid;
    int aval;
  }mach;
public:
  Mach_que(int n){
    for (int i = 1; i<= n;i++){
      mach temp{i,0,0};
      free.push_back(temp);
    }
  }
  void assign(const task& a){
    if (!free.empty()) {
  			mach temp = free.front();
  			temp.aval = a.time;
  			temp.tid = a.id;
  			busy.push_back(temp);
  			free.pop_front();
  		}
  }
  void flu(){
    for(auto& i:busy){
      i.aval--;
      if(i.aval == 0){
        cout<<"machine"<<busy.front().id<<"finish task "<<busy.front().tid<<" \
and free.\n";
        mach temp = busy.front();
        temp.tid = 0;
        free.push_back(temp);
        busy.pop_front();
      }
    }
  }
  bool hasbusy(){
    return !busy.empty();
  }
  bool hasfree(){
    return !free.empty();
  }
private:
  deque<mach> free;
  deque<mach> busy;
};
