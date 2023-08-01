#include <iostream>
using namespace std;
#include<unordered_map>

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int,int> obj;
    int maxfreq=0;
    int ans;

    for(int i=0;i<n;i++)
    {
       ++obj[arr[i]];
       maxfreq=max(maxfreq,obj[arr[i]]);
    }

    for(int i=0;i<n;i++)
    {
        if(obj[arr[i]] == maxfreq)
        return arr[i];
    }

}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i=0; i<n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr,n);

    delete[] arr;
}
