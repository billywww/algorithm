/*背包问题的物品间存在某种“依赖”的关系。也就是说，i依赖于j，表示若选物品i，则必须选物品j。*/
#include<iostream>
using namespace std;

int max(int m, int n, int( *pr)[3], int(* im)[3], int * f,int *k) {
	m = m / 10;
	int *val = new int[m];
	int i, j;
	for (i = 0; i < m; i++) {
		val[i] = 0;
	}
	for (i = 0; i < n; i++) {
		for (j = m; j >= pr[i][0]; j--) {
			if (!f[i]) {
				val[j] = val[j] > val[j - pr[i][0]] + im[i][0] ? val[j] : val[j - pr[i][0]] + im[i][0];
			}
			else {
				if (f[i] == -1) {
					if(pr[i][0]<=j){
					val[j] = val[j] > val[j - pr[i][0]] + im[i][0] ? val[j] : val[j - pr[i][0]] + im[i][0];
					}
					int z = 1;
					if (z < k[i] && pr[i][0] + pr[i][1] <= j) {
						int tp = pr[i][0] + pr[i][1];
						int ti = im[i][0] + im[i][1];
						val[j] = val[j] > val[j - tp] + ti ? val[j] : val[j - tp] + ti;
						z++;
					}
					if (z < k[i] && pr[i][0] + pr[i][2] <= j) {
						int tp = pr[i][0] + pr[i][2];
						int ti = im[i][0] + im[i][2];
						val[j] = val[j] > val[j - tp] + ti ? val[j] : val[j - tp] + ti;
					}
					if (z < k[i] && pr[i][0] + pr[i][1]+pr[i][2] <= j) {
						int tp = pr[i][0] + pr[i][1]+pr[i][2];
						int ti = im[i][0] + im[i][1]+im[i][2];
						val[j] = val[j] > val[j - tp] + ti ? val[j] : val[j - tp] + ti;
					}
				}
			}
		}
	}
	return 10*val[m];
}

int main() {
	/*
	1000 5
	800 2 0
	400 5 1
	300 5 1
	400 3 0
	500 2 0
	*/
	int m, n;
	cin >> m >> n;
	int i = 0;
	int (*pr)[3] = new int[n][3];
	int (*im)[3] = new int[n][3];
	int *f = new int[n];
	int k[200]={0};
	while (i < n) {
		cin >> pr[i][0] >> im[i][0] >> f[i]; // price : impotance : master or appended
		pr[i][0] = pr[i][0] / 10;
		im[i][0] = pr[i][0] * im[i][0];
		if (f[i]!= 0) {
			pr[f[i] - 1][++k[i]] = pr[i][0];
			im[f[i] - 1][k[i]++] = im[i][0];
			f[f[i] - 1] = -1;
		}
		i++;
	}
	cout<<max(m, n, pr, im, f, k)<<endl;
	getchar(); getchar();
	return 0;
}
