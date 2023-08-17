#include<bits/stdc++.h>
using namespace std;


int minSteps(int n)
{
    if(n<=1)
    return 1;

    long long mod=1e9+7;
    long long a=1,b=1,c=2;

    for(int i=0;i<=n-3;i++)
    {
        long ans=(a+b+c)%mod;
        a=b;
        b=c;
        c=ans;
    }

    return c;



}
int main()
{
    int t;
    cin>>t;

    int n;
    while(t--)
    {
        cin>>n;
        cout<<minSteps(n)<<endl;
    }
    // take input from the user.
    return 0;
}
