#include<iostream>
using namespace std;

int minCount(int n)
{
	int *dp=new int[n+1];
	dp[0]=0;
	dp[1]=1;

	for(int i=2; i<=n;i++)
	{
		dp[i]=INT_MAX;
		for(int j=1;i-(j*j)>=0;++j)
		{
	         	dp[i]=min(dp[i],dp[i-(j*j) ] );
		}
	dp[i]+=1;
	}

	int res= dp[n];
	delete []dp;
	return res;
}

int main()
{
    cout<<minCount(5);
}
