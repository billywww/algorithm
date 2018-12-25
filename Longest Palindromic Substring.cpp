/*
manacher算法
给定一个字符串 s，找到 s 中最长的回文子串
2019/9/14
https://blog.csdn.net/qq_40181068/article/details/80141563
*/

#include<stdio.h>
#include<malloc.h>
#include<string.h>

char * init (char * s){
    char * str = (char*)malloc(sizeof(char)*10000);
    int k = 0;
    str[k++] = '*';
    while(*s){
        str[k++] = *s;
        str[k++] = '*';
        s++;
    }
    return str;
}

char* longestPalindrome(char* s) {
  char * str =(char*)malloc(sizeof(char)*10000);
  str = init(s);
  int n= strlen(str);
  int p[10000] = {0};
  int maxl=0;
  int m=1;
  int co = 0;
  p[0]=1;
  int i, re;
  for(i=1;i<n;i++){
    if(i<m && 2*co-i>=0){
       p[i] = p[2*co-i] < (m-i) ? p[2*co-i] : (m-i);
    }
    else
    p[i]=1;
    while(str[i+p[i]]==str[i-p[i]] && i-p[i] >= 0 && 1+p[i] <n){p[i]++;}//暴力解法
    if(i+p[i]>m){
      m=i+p[i];
      co=i;
    }
    if(maxl < p[i]-1 ){
      maxl = p[i]-1;
      re = i;
    }
  }
    char * arr = (char*)malloc(sizeof(char)*(maxl+1));
    arr = &s[re/2-maxl/2];
    arr[maxl] = '\0';

    return arr;
}
