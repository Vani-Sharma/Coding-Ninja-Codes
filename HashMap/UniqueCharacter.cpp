#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;
  string uniqueChar(string str) {

	unordered_map<char,int>obj;
	string output;
	int j=0;

	for(int i=0;i<str.length();i++)
	{
		if(obj.count(str[i])>0)
		continue;


		output.push_back(str[i]);
		obj[str[i]]=1;
		j++;

	}
	return output;
}

int main()
{
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
