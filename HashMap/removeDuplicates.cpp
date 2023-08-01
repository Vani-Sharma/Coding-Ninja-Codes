#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(int *a,int size)
{
    vector<int>output;
    unordered_map <int,bool> seen;

    for(int i=0;i<size;i++)
    {
        if(seen.count(a[i])>0)
        {
           continue;
        }
         output.push_back(a[i]);
         seen[a[i]]=true;

    }

    return output;
}

int main()
{
    int arr[]={1,2,3,4,2,3,2,5,6,1,6,7,2};
    int size=sizeof(arr)/sizeof(arr[0]);

    vector<int>output=removeDuplicates(arr,size);

    for(int i=0;i<output.size();i++)
        cout<<output[i]<<endl;
}
