/*
找出两个字符串的最长公共连续子串的长度
2018/9/13
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//动态规划 Ⅰ：n^2
int maxsubarr(char * arr1, int arr1size, char * arr2, int arr2size){
  int table[arr1size][arr2size]={0};

  int max = 0;

  for(int i = 0; i < arr2size; i++){
    table[0][i] = (arr1[0] == arr2[i] ? 1 : 0);
  }
  for(int i = 1; i < arr1size; i++){
    table[i][0] = (arr2[0] == arr1[i] ? 1 : 0);
    for(int j = 1; j < arr2size; j++){
        if (arr1[i] == arr2[j]){
          table[i][j] = table[i-1][j-1] + 1;
          max = max > table[i][j] ? max : table[i][j];
        }

    }
  }
  return max;
}

int main(void){
	char str1[1000],str2[1000];
	printf("str1 :");
	gets(str1);
	printf("str2 :");
	gets(str2);
	int len = maxsubarr(str1,strlen(str1),str2,strlen(str2));
	printf("length  :%d\n",len);
	system("pause");
	return 0;

}

//暴力解法 Ⅰ：n^4
// int findsubarray(char * arr1, int arr1size, char * arr2, int arr2size){
//
// }
//
// int maxsubarr(char * arr1, int arr1size, char * arr2, int arr2size){
//   if(arr1size == 0 || arr2size == 0){
//     return 0;
//   }
//
//   int max = 0;
//   for(int i = 0; i < arr1size; i++){
//     for(int j = arr1size - 1; j >= 0; j--){
//       int r = findsubarray(&arr1[i], j-i+1, arr2, arr2size);
//       if(r){
//         max = max > r ? max : r;
//         break;
//       }
//     }
//   }
//   return max;
// }

//暴力解法 Ⅱ：n^3
// int maxsubarr(char * arr1, int arr1size, char * arr2, int arr2size){
//     if(arr1size == 0 || arr2size == 0){
//       return 0;
//     }
//
//     int max = 0;
//     for(int i = 0; i < arr1size; i++){
//       for(int j = 0; j < arr2size; j++){
//         int temp = 0;
//         int s1 = i;
//         int s2 = j;
//         while(arr1[s1] == arr2[s2]){
//           s1++; s2++;
//           temp++;
//         }
//         max = max > temp ? max : temp;
//       }
//     }
//
//     return max;
//   }
