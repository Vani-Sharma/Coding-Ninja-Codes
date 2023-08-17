#include<iostream>
using namespace std;

int fibonacci(int n,int *ans)
{
    if(n<=1)
        return n;

    if(ans[n]!=-1)
    return ans[n];

    int a=fibonacci(n-1,ans);
    int b=fibonacci(n-2,ans);

    ans[n]=a+b;
    cout<<ans[n]<<" ";
    return a+b;

}

int fibo_dp(int n)
{
    int *ans=new int[n+1];
     ans[0]=0;
     ans[1]=1;

    cout<<endl;
    for(int i=2;i<=n;i++)
    {
        ans[i]=ans[i-1]+ans[i-2];
        cout<<ans[i]<<" ";
    }

    return ans[n];

}
void fibo(int n)
{
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++)
        ans[i]=-1;
    //---> memoization
    fibonacci(n,ans);
}

int main()
{
    int n;
    cin>>n;

    fibo(n);
    fibo_dp(n);
}
