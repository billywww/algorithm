/*
将字符串转为整数。
在找到第一个非空字符之前，需要移除掉字符串中的空格字符。如果第一个非空字符是正号或负号，选取该符号，并将其与后面尽可能多的连续的数字组合起来，这部分字符即为整数的值。
如果第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
字符串可以在形成整数的字符后面包括多余的字符，这些字符可以被忽略，它们对于函数没有影响。
当字符串中的第一个非空字符序列不是个有效的整数；或字符串为空；或字符串仅包含空白字符时，则不进行转换。
若函数不能执行有效的转换，返回 0
2018/9/16
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int myAtoi(char* str) {
  if(strlen(str) == 0){
    return 0;
  }
  char * p = str;
  while(*p == ' ' && *p != '\0'){            //首个非空字符
    p++;
  }

  if(*p == '\0'){                        //空字符
    return 0;
  }        
  if(*p != '+' &&*p != '-' && (*p < 48 || *p >57)){         //首个字符是否合法
      return 0;
  }
  else{
    int flag = 1;
    long re = 0;
    if(*p == '+' || *p == '-'){          //首字符为 + - 符号
      flag = (*p == '+' ? 1 : 0);
      p++;
    }

   while (*p == '0'){          //首字符为0时
      p++;
    }

    while(*p != '\0' && *p >= 48 && *p <= 57){
      if(*p >= 48 && *p <= 57){
        re = re * 10 + *p - '0';
        if(re < -1 * pow(2,31) || re > pow(2,31) - 1){return flag == 1 ? pow(2,31) - 1 :  -1 * pow(2,31);}
        p++;
      }
      else{
        p++;
      }
    }
    if(flag){return re;}
      else{return -re;}
  }
}
