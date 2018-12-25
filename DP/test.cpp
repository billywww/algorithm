#include<iostream>
#include<cstring>
using namespace std;
const int N=100;
char X[N],Y[N],Z[N];
int dp[N][N];
int b[N][N];
int LCSLength(char *x,char *y,int m,int n){
	int i,j;
	for(i=1;i<=m;i++) dp[i][0]=0;
	for(j=1;j<=n;j++) dp[0][j]=0;
	for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
	{
		if(x[i-1]==y[j-1])  //
		{
			dp[i][j]=dp[i-1][j-1]+1;
			b[i][j]=1;
		}
		else if(dp[i-1][j]>=dp[i][j-1])
		{
			dp[i][j]=dp[i-1][j];
			b[i][j]=2;
		}
		else
		{
			dp[i][j]=dp[i][j-1];
			b[i][j]=3;
		}
	 }
	 return dp[m][n];
}
void LCS(int i,int j,char *z,int (*b)[N])
{
	if(i==0||j==0) return;
	if(b[i][j]==1)
	{
		LCS(i-1,j-1,z,b);
		cout<<z[i-1];         //
	}
	else if(b[i][j]==2)
	{
		LCS(i-1,j,z,b);
	}
	else
	{
		LCS(i,j-1,z,b);
	}
}
int main()
{
	gets(X);
	gets(Y);
	int m=strlen(X);
	int n=strlen(Y);
  cout<<(X[m]==Y[n])<<' ';
	cout<<LCSLength(X,Y,m,n)<<endl;
	LCS(m,n,X,b);     //
	return 0;
}
