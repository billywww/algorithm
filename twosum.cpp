#include<stdio.h>
#include<malloc.h>
int* work(int * arr, int tar, int k){
	int *r =(int*)malloc(sizeof(int)*100);
	int t = 1;
	//
	// for(int i=0; i<k; i++){
	// 	for(int j=i+1; j<k; j++){
	// 		if(arr[i]+arr[j] == tar){
	// 			r[t++] = i;
	// 			r[t++] = j;
	// 		}
	// 	}
	// }
	// r[0] = t-1;
	int left = 0;
	int right = k;
	while(left <= right){
		if(arr[left]+arr[right] == tar){
						r[t++] = left;
						r[t++] = right;
		}
		else if(arr[left]+arr[right] <= tar){
			left++;
		}
		else{
			right--;
		}
	}
	r[0] = t-1;
	return r;
}

void sort(int * arr,int k){

}

int main(){
	int arr[100];
	int k;
	int target;

	scanf("%d",&k);

	for(int i=0; i<k; i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&target);
	sort(arr,k);
	int * result = work(arr,target,k);
	for(int i=1;i<=result[0];i++){
		printf("%d",result[i]);
	}
	free(result);
	return 0;
}
