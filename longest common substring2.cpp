/**
找出两个字符串的最长公共连续子串的长度
2018/9/13
**/

#include "stdio.h"
#include "string.h"
#include "stdlib.h"


int longest_common_substring(char *str1, char *str2){
	int i,len1,len2,len,s1_start,s2_start,idx,curmax,max;
	len1 = strlen(str1);
	len2 = strlen(str2);
	len = len1 + len2;
	max = 0;
	for(i = 0 ; i < len ; i++)
	{
		s1_start = s2_start = 0;
		if(i < len1)
			s1_start = len1 - i;    //每次开始匹配的起始位置
		else
			s2_start = i - len1;
		curmax = 0;
		for(idx = 0 ; ( s1_start + idx < len1 ) && ( s2_start + idx < len2 ); idx++ )
		{
			if(str1[s1_start+idx]==str2[s2_start+idx])
				curmax++;
			else     //只要有一个不相等，就说明相等的公共字符断了，不连续了，要保存curmax与max中的最大值，并将curmax重置为0
			{
				max = curmax > max ? curmax : max;
				curmax = 0;
			}
		}
		max = curmax > max ? curmax : max;
	}
	return max;
}

int main(void){
	char str1[1000],str2[1000];
	printf("str1 :");
	gets(str1);
	printf("str2 :");
	gets(str2);
	int len = longest_common_substring(str1, str2);
	printf("length : %d\n",len);
	system("pause");
	return 0;

}
