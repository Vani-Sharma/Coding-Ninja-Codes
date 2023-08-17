#include<iostream>
using namespace std;

int minStepto1(int n)
{
 //   ---recursion
   if(n<=1)
    return 0;

   int x=minStepto1(n-1);
   int y=INT_MAX,z=INT_MAX;

   if(n%2==0)
    y=minStepto1(n/2);

   if(n%3==0)
    z=minStepto1(n/3);

    int ans=min(x,min(y,z))+1;

    return ans;
}

int minStepto1(int n,int *ans)
{
    //-- memoization top-down approach
    if(n<=1)
        return 0;

    if(ans[n]!=-1)
        return ans[n];

   int x=minStepto1(n-1);
   int y=INT_MAX,z=INT_MAX;

   if(n%2==0)
    y=minStepto1(n/2);

   if(n%3==0)
    z=minStepto1(n/3);

    ans[n]=min(x,min(y,z))+1;

    return ans[n];

}
int countStepsToOne(int n) {
    //-- dp  bottom-up approach
  int *ans = new int[n + 1];
  ans[1] = 0;
  for (int i = 2; i <= n; i++) {
    int a = ans[i - 1];
    int b = INT_MAX;
    int c = INT_MAX;
    if (i % 2 == 0) {
      b = ans[i / 2];
    }
    if (i % 3 == 0) {
      c = ans[i / 3];
    }
    ans[i] = 1 + min(a, min(b, c));
  }
  return ans[n];
}

int main()
{
    int n;
    cin>>n;

    int *ans=new int[n+1];
    for(int i=0;i<=n;i++)
        ans[i]=-1;

    cout<<minStepto1(n,ans);
    cout<<countStepsToOne(n);
    //cout<<minStepto1(n);
}

