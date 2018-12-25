//全排列问题

#include<iostream>
using namespace std;

void full_permutation(int * a , int start, int end ,int num){
	if( start == end){
		for(int j = 0 ; j< num ;j++){
				cout<<a[j];
			}
			cout<<endl;
	}
	else{
		for (int i = start ; i <= end ; i++){
			swap(a[i],a[start]);


			full_permutation(a ,start + 1, end , num );
			swap(a[i],a[start]);
		}
	}
}


int main(){
	int * arr = new int[100];
	int n;
	cin >> n;
	for (int i = 0; i<n;i++){
		cin >> arr[i];
	}
	full_permutation(arr,0,n-1,n);
}
