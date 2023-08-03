#include<iostream>
#include<string>
using namespace std;
template< typename V>

class MapNode
{
public:
    string key;
    V value;
    MapNode<V>*next;

    MapNode(string key, V value)
    {
        this->key=key;
        this->value=value;
        next=NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template<typename V>
class ourmap
{
    public:
    MapNode<V>**bucket;
    int count;
    int numBucket;

    ourmap()
    {
         count=0;
        numBucket=5;
         bucket=new MapNode<V>*[numBucket];
        for(int i=0;i<numBucket;i++)
           bucket[i]=NULL;
    }
    ~ourmap()
    {
        for(int i=0;i<numBucket;i++)
           delete bucket[i];

        delete [] bucket;
    }

    private:
     int getBucketIndex(string key)
    {
        int hashcode;
        int currentCoeff=1;
        for(int i=key.length()-1;i>=0;i--)
        {
            hashcode+=key[i]*currentCoeff;
            hashcode=hashcode%numBucket;
            currentCoeff*=37;
            currentCoeff%numBucket;
        }

        return hashcode%numBucket;
    }


    public:
    int size()
    {
        return count;
    }

    void insert(string key,V value)
    {
        int bucketIndex=getBucketIndex(key);
        MapNode<V>*head=bucket[bucketIndex];

        while(head!=NULL)
        {
            if(head->key==key)
            {
                head->value=value;
                return;
            }
            head=head->next;
        }

        head=bucket[bucketIndex];
        MapNode<V>*node=new MapNode<V>(key,value);
        node->next=head;
        bucket[bucketIndex]=node;
        count++;
    }

    V deleted(string key)
    {
        int bucketIndex=getBucketIndex(key);
        MapNode<V>*head=bucket[bucketIndex];
        MapNode<V>*prev=NULL;
        while(head!=NULL)
        {
            if(head->key==key)
            {
                if(prev==NULL)
                    bucket[bucketIndex]=head->next;

                else
                    prev->next=head->next;

                V value=head->value;
                head->next=NULL;
                delete head;
                count--;
                return value;
            }

            prev=head;
            head=head->next;
        }

        return 0;
    }

    V getValue(string key)
    {
        int bucketIndex=getBucketIndex(key);
        MapNode<V>*head=bucket[bucketIndex];

        while(head!=NULL)
        {
            if(head->key==key)
                return head->value;

            head=head->next;
        }

        return 0;
    }
};

int main()
{
    ourmap<int> obj;
    obj.insert("abc",3);
    obj.insert("gbc",32);
    obj.insert("abgh",3566);
    obj.insert("jfe",12);
    obj.insert("djfieg",74);
    obj.insert("ddji",3814);
    obj.insert("xmnv",48569);
    obj.insert("abc",458);

    cout<<"No. of elements in hashmap are : "<<obj.size()<<endl;
    cout<<"Value of abc in hashmap is : "<<obj.getValue("abc")<<endl;

    cout<<"deleted value is : "<<obj.deleted("xmnv")<<endl;
    cout<<"No. of elements in hashmap are : "<<obj.size()<<endl;
}
