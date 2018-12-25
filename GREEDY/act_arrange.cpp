#include<iostream>


/*end_time is sorted ascending*/
void greedselect(int n,int *start_time,int *end_time,bool *mark){
  mark[0] = true;

  int current_act = 0;
  for(int i = 1; i < n;i++){
    if(start_time[i] >= end_time[current_act]){
      current_act = i;
      mark[i] = true;
    }
    else mark[i] = false;
  }
}

void sort_asc(int n,int *s,int *e){
  for(int i = 1; i < n; i++){
    int j = i-1;
    while(e[i]<e[j]&&j>=0){
      j--;
    }
    int temps = s[i]; int tempe = e[i];
    for(int k = i-1 ;k > j;k--){
      e[k+1] = e[k];
      s[k+1] = s[k];
    }
    e[j+1] = tempe; s[j+1] = temps;
  }
}

int main(){
  int s[]={12,3,0,5,3,5,6,8,8,2,1};
  int e[]={14,5,6,7,8,9,10,11,12,12,4};
  int n = 11;
  bool mark[11];
  sort_asc(n,s,e);
  greedselect(n,s,e,mark);
  for(int i = 0;i<11;i++)
  std::cout<<mark[i];
  return 0;
}
