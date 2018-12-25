/*
给定一个 32 位有符号整数，将整数中的数字进行反转。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0
2018/9/16
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int reverse(int x) {

    long re = 0;
    int flag = (x > 0 ? 1 : 0);
    x = (x > 0 ? x : -x);
    while(x){
        re = re * 10 + x % 10;
        x = x / 10;
    }
    re = (flag == 1 ? re : -re);

    if(re < -1 * pow(2,31) || re > pow(2,31) - 1){
        return 0;
    }
    return re;
}

int main(){

}
