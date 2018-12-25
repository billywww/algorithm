//给定一个字符串，找出不含有重复字符的最长子串的长度

#include<stdio.h>


//方法三：优化的滑动窗口
int lengthOfLongestSubstring3(char* s) {
    int result = 0;

    char *p = s;
    char *t = p;
    int mark[150] = {0};
    int temp = 0;

      while(*t && *p){
        if(mark[*t] == 0){
          temp++;
          mark[*t] = t-s+1;
          t++;
        }
        else{
          result = result > temp ? result : temp;
          temp -= (mark[*t]-(p-s));
          for(int i = p - s;i < mark[*t];i++){
              mark[*p] = 0;
              p++;
          }
        }
      }
    result = result > temp ? result : temp;


    return result;
}

//复杂度： 2n
int lengthOfLongestSubstring2(char* s) {
    int result;
    int max = 0;
    char *p = s;
    while(*p){
      char *t = p;
      int temp = 0;
      int mark[150] = {0};
      while(*t){
        if(mark[*t] == 0){
          temp++;
          mark[*t] = 1;
          t++;
        }
        else{
          break;
        }
      }
      result = max > temp ? max : temp;
      max = result;
      p++;
    }
    return result;
}


//复杂度：n*n
int lengthOfLongestSubstring1(char* s) {
    int result = 0;
    int max = 0;
    char *p = s;
    char *t = p;
    int mark[150] = {0};
    int temp = 0;
    while(*p){

      while(*t){
        if(mark[*t] == 0){
          temp++;
          mark[*t] = 1;
          t++;
        }
        else{
          mark[*p] = 0;
          break;
        }
      }
      result = max > temp ? max : temp;
      max = result;
      temp--;
      p++;
    }
    return result;

}
