//模拟工作栈实现非递归算法

#include<iostream>
using namespace std;


typedef struct n{
  int num;
  int from;
  int to;
  int temp;
  int step;
}Simulated_Node;

typedef struct s{
  struct n node[100];
  int top;
}Simulated_Stack;

void init_stack(Simulated_Stack* s){
  s->top = 0;
}

int push_stack(Simulated_Stack *s,Simulated_Node n){
  if( (s->top) >= 100){
    return 0;
  }
  s->node[s->top].num = n.num;
  s->node[s->top].from = n.from;
  s->node[s->top].to = n.to;
  s->node[s->top].temp = n.temp;
  s->node[s->top].step = n.step;
  s->top += 1;
  return 1;
}

int stack_empty(Simulated_Stack* s){
  if(s->top == 0){
    return 1;
  }
  else return 0;
}

Simulated_Node pop_stack(Simulated_Stack* s){

  Simulated_Node *r = new Simulated_Node;
  r->num = s->node[s->top-1].num;
  r->from = s->node[s->top-1].from;
  r->to = s->node[s->top-1].to;
  r->temp = s->node[s->top-1].temp;
  r->step = s->node[s->top-1].step;
  s->top -= 1;
  return *r;
}

void hanoi(int n,int a,int b,int c){
  Simulated_Stack *S = new Simulated_Stack;
  init_stack(S);
  Simulated_Node f = {n,a,b,c,0};
  push_stack(S,f);
  while(!stack_empty(S)){
    Simulated_Node s = pop_stack(S);
    switch(s.step){
      case 0:
        if(s.num == 0){
        break ;}
        else{
          s.step = 1;
          push_stack(S,s);
          Simulated_Node t = {s.num-1,s.from,s.temp,s.to,0};
          push_stack(S,t);
          break;
        }
      case 1:{
        s.step = 2;
        push_stack(S,s);
        cout << "move from "<< s.from <<" to "<< s.to << endl;
        Simulated_Node q = {s.num-1,s.temp,s.to,s.from,0};
        push_stack(S,q);
        break;
      }
      case 2:break;
    }
  }
  delete S;
  return;
}

int main(){
  int n;
  cin >> n;
  hanoi(n,1,2,3);
  return 0;
}
