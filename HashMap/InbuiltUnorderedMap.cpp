#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int main()
{
    unordered_map<string,int>obj;
    pair <string,int> p("abc",1);

    obj.insert(p);
    obj["def"]=2;

    cout<<obj["abc"]<<endl;
    cout<<obj.at("def")<<endl;

    cout<<obj["geh"]<<endl;

    //check presence ----> count return 0 or 1
    if(obj.count("ghi")>0)
        cout<<obj["ghi"]<<endl;
    else
        cout<<"ghi not present"<<endl;

    //size
    cout<<obj.size()<<endl;

    //erase
    cout<<obj.erase("abc");
    if(obj.count("abc")>0)
        cout<<obj["abc"]<<endl;
    else
        cout<<"abc not present"<<endl;


}

