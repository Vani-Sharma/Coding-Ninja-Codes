#include<iostream>
using namespace std;

int balancedBTs(int n) {
    // Write your code here
    if(n<=1)
    return 1;

   int a=balancedBTs(n-1);
   int b=balancedBTs(n-2);
   int mod=1e9+7;

    long long int temp1=((long long int)a*a)%mod;
     long long int temp2=(2*(long long int)a*b)%mod;

     int ans=((temp1+temp2)%mod);
     return ans;

}

int balancedBTsDP(int n) {
    // dp
    if(n<2)
    return 1;

    long long int mod=1e9+7;

    int dp0=1,dp1=1,dpn;

    for(int i=2;i<=n;i++)
    {
        dpn=(((long long int)dp1*dp1)%mod) + ((2*(long long int)dp1*dp0)%mod);
        dpn=dpn%mod;

        dp0=dp1;
        dp1=dpn;
    }

  return dpn;
}

int main()
{
    int h;
    cin>>h;

    cout<<balancedBTsDP(h);
}
