/*
将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数
2018/9/15
*/

#include<stdio.h>
#include<string.h>
#include<malloc.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);
    int k = 2 * numRows - 2;  //每组k个
    if(k == 0 ){
        k =1;
    }
    char * re = (char*)malloc(sizeof(char)*10000);
    int c = 0;
    for(int  i = 0; i < numRows; i ++){
        int j = i;
        int a = k - 2*j;
        while(j < len){
          re[c++] =  s[j];
          if(j+a < len && j % k != 0 && (j+numRows-1)%k != 0){
            re[c++] = s[j+a];
          }
          j = j + k;
        }
    }
    re[c] = '\0';
    return re;
}
