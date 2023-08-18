#include <bits/stdc++.h>
using namespace std;

int getCost(int**input,int i,int j,int m,int n)
{
    // --normal recursive approach
	if(i+1==m && j+1==n)
	return input[i][j];

	if(i>=m || j>=n)
    return INT_MAX;

        int x = getCost(input, i + 1, j + 1, m, n);
        int y = getCost(input, i, j + 1, m, n);
        int z = getCost(input, i + 1, j, m, n);

        return input[i][j] + min(x, min(y, z));
}

int getcostMemo(int**input,int i,int j,int m,int n, vector<vector<int>>output)
{
    // --memoization
        if(i+1==m && j+1==n)
	return input[i][j];

        if(output[i][j]!=-1)
        return output[i][j];

	if(i>=m || j>=n)
        return INT_MAX;

        int x = getCost(input, i + 1, j + 1, m, n);
        int y = getCost(input, i, j + 1, m, n);
        int z = getCost(input, i + 1, j, m, n);

        output[i][j]= input[i][j] + min(x, min(y, z));
        return output[i][j];
}

int minCostPathDP(int **input,int m,int n)
{
    vector<vector<int>>output(m,vector<int>(n));
    output[m-1][n-1]=input[m-1][n-1];

    //filling last row from n-2 column
    for(int j=n-2;j>=0;j--)
        output[m-1][j]=input[m-1][j]+output[m-1][j+1];

    //filling last column from m-2 row
    for(int i=m-2;i>=0;i--)
        output[i][n-1]=input[i][n-1]+output[i+1][n-1];

    //filling remaining cells
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            output[i][j]=input[i][j]+min(output[i+1][j],min(output[i][j+1],output[i+1][j+1]));
        }
    }

    return output[0][0];
}
int minCostPath(int **input, int m, int n)
{
	//Write your code here
	// return getCost(input,0,0,m,n);
        vector<vector<int>>output(m,vector<int>(n,-1));
        return getcostMemo(input,0,0,m,n,output);

}
int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPathDP(arr, n, m) << endl;
}
