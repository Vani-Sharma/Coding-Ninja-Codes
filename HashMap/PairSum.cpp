#include<iostream>
#include<unordered_map>
using namespace std;

int pairSum(int *arr,int n)
{
    unordered_map<int,int> obj;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int cmp= -arr[i];
        if(obj.find(cmp)!=obj.end())
            cnt+=obj[cmp];


        ++obj[arr[i]];
    }

    return cnt;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<pairSum(arr,n);
}
